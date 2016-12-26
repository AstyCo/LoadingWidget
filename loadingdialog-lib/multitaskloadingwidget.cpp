#include "multitaskloadingwidget.h"
#include "ui_multitaskloadingwidget.h"

#include "loadingdialog.h"

#include <QDebug>

MultiTaskLoadingWidget::MultiTaskLoadingWidget(HTaskManager *manager, const QString &title, const QString &description, QWidget *parent, Qt::WindowFlags fl)
    : QWidget(parent,fl),
      ui(new Ui::MultiTaskLoadingWidget)
{
    init();
    setWindowTitle(title);
    setDescription(description);
    setManager(manager);
}

MultiTaskLoadingWidget::MultiTaskLoadingWidget(HTaskManager *manager, const QString &title, QWidget *parent, Qt::WindowFlags fl)
    : QWidget(parent,fl),
      ui(new Ui::MultiTaskLoadingWidget)
{
    init();
    setWindowTitle(title);
    setManager(manager);
}

MultiTaskLoadingWidget::MultiTaskLoadingWidget(HTaskManager *manager, QWidget *parent, Qt::WindowFlags fl)
    : QWidget(parent,fl),
      ui(new Ui::MultiTaskLoadingWidget)
{
    init();
    setManager(manager);
}

MultiTaskLoadingWidget::~MultiTaskLoadingWidget()
{
    removeManagerDepends();
    delete ui;
}

void MultiTaskLoadingWidget::init()
{
    ui->setupUi(this);

    setWindowModality(Qt::ApplicationModal);
    setAttribute(Qt::WA_DeleteOnClose, true);
    setWindowFlags( Qt::SubWindow | Qt::Dialog | Qt::WindowTitleHint | Qt::WindowStaysOnTopHint);

    // center on parent
    moveToParentCenter();

    _manager = NULL;
    ui->verticalLayout->setAlignment(Qt::AlignTop);
    ui->verticalLayoutLoadingItems->setAlignment(Qt::AlignTop);
}

void MultiTaskLoadingWidget::removeManagerDepends()
{
    if(_manager)
    // disconnects all signals from last manager, that is the probably reason of QPointer
        _manager->disconnect(this);

    foreach(HTask *task, _qhashTasks.keys())
        removeTask(task);
}

void MultiTaskLoadingWidget::initManager()
{
    const QList<HTask *> &managerTasks = _manager->tasks();
    for(int i = 0; i < managerTasks.size(); ++i)
        addTask(managerTasks[i]);

    connect(_manager, SIGNAL(started()), this, SLOT(onStarted()));
    connect(_manager, SIGNAL(finished()), this, SLOT(onFinished()));
    connect(_manager, SIGNAL(taskAdded(HTask*)), this, SLOT(addTask(HTask*)));
    connect(_manager, SIGNAL(taskRemoved(HTask*)), this, SLOT(removeTask(HTask*)));
    connect(_manager, SIGNAL(taskStarted(HTask*)), this, SLOT(onTaskStarted(HTask*)));
    connect(_manager, SIGNAL(taskFinished(HTask*)), this, SLOT(onTaskFinished(HTask*)));
}

void MultiTaskLoadingWidget::addTask(HTask *task)
{
    LoadingItem *item = new LoadingItem();
    ui->verticalLayoutLoadingItems->addWidget(item);
    item->setProcessName(task->title());
    if(task->cancelable()){
        item->showSkip();
        connect(item,SIGNAL(skip()),task,SLOT(cancel()));
        connect(task,SIGNAL(finished()),item,SLOT(hideSkip()));
    }
    else
        item->hideSkip();

    _qhashTasks.insert(task,item);
    adjustSize();
}

void MultiTaskLoadingWidget::removeTask(HTask *task)
{
    if(!_qhashTasks.contains(task))
    {
        qWarning("LoadingWidget::removeTask:: Hash doesn't contain removed task");
        return;
    }
    ui->verticalLayoutLoadingItems->removeWidget(_qhashTasks[task]);
    _qhashTasks[task]->deleteLater();
    _qhashTasks.remove(task);
}

void MultiTaskLoadingWidget::onTaskStarted(HTask *task)
{
    if(!_qhashTasks.contains(task))
    {
        qWarning("LoadingWidget::onTaskStarted:: Hash doesn't contain task");
        return;
    }
    _qhashTasks[task]->onStarted();
}

void MultiTaskLoadingWidget::onTaskFinished(HTask *task)
{
    if(!_qhashTasks.contains(task))
    {
        qWarning("LoadingWidget::onTaskFinished:: Hash doesn't contain task");
        return;
    }
    _qhashTasks[task]->onCompleted();
}

QPointer<HTaskManager> MultiTaskLoadingWidget::manager() const
{
    return _manager;
}

void MultiTaskLoadingWidget::setManager(HTaskManager *manager)
{
    if(manager == NULL)
        return;
    if(_manager)
        removeManagerDepends();

    _manager = manager;
    initManager();
}

void MultiTaskLoadingWidget::setDescription(const QString &text)
{
    ui->labelDescription->setText(text);
}

void MultiTaskLoadingWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    moveToParentCenter();
}

void MultiTaskLoadingWidget::onStarted()
{
    if(cancelableTasks())
        ui->pushButtonCancel->setEnabled(true);
    else
        ui->pushButtonCancel->setEnabled(false);
    show();
}

void MultiTaskLoadingWidget::onFinished()
{
    close();
}

void MultiTaskLoadingWidget::on_pushButtonCancel_clicked()
{
    if(_manager)
        _manager->cancelRuns();
}

bool MultiTaskLoadingWidget::cancelableTasks() const
{
    if(_qhashTasks.empty())
        return false;
    foreach(HTask *task,_qhashTasks.keys())
        if(!task->cancelable())
            return false;
    return true;
}

void MultiTaskLoadingWidget::moveToParentCenter()
{
    if(parentWidget()!= NULL)
    {
        const QPoint global = parentWidget()->mapToGlobal(parentWidget()->rect().center());
        move(global.x() - width() / 2, global.y() - height() / 2);
    }
}
