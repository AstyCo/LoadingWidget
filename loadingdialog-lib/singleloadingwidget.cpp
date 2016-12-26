#include "singleloadingwidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QPushButton>


SingleLoadingWidget::SingleLoadingWidget(HTask *task,
                                         HTaskManager *manager,
                                         const QString &title,
                                         const QString &description,
                                         LoadingDialog::PlayMode playMode,
                                         QWidget *parent)
    : LoadingDialog(parent)
{
    init();
    setDescription(description);
    setProcessName(title);
    setPlayMode(playMode);
    setManager(manager);
    setTask(task);
}

void SingleLoadingWidget::init()
{
    _task = NULL;
    setAttribute(Qt::WA_DeleteOnClose);
    setVisualWidget(LoadingDialog::widgetProgressBar);
    // extra setup .ui
    QVBoxLayout *parentLayout = qobject_cast<QVBoxLayout*>(layout());
    if(!parentLayout){
        Q_ASSERT_X(false,"SingleLoadingWidget::init", "parent layout not QVBoxLayout");
        return;
    }
    QHBoxLayout *bottomLayout = new QHBoxLayout();
    QSpacerItem *spacer = new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Minimum);
    QPushButton *pushButtonCancel = new QPushButton(QString::fromUtf8("Отмена"));

    bottomLayout->addItem(spacer);
    bottomLayout->addWidget(pushButtonCancel);

    parentLayout->addLayout(bottomLayout);
    connect(pushButtonCancel,SIGNAL(clicked(bool)),this,SIGNAL(cancel()));
    // end of extra setup .ui
}

void SingleLoadingWidget::setManager(const QPointer<HTaskManager> &manager)
{
    _manager = manager;
    QList<HTask *> tasks = manager->tasks();
    if(tasks.empty())
        return;

    setTask(tasks[0]);
}

void SingleLoadingWidget::setTask(HTask *task)
{
    if(_task.data() == task)
        return;
    if(_task){
        _task->disconnect(this);
        disconnect(_task);
    }

    _task = task;
    if(!_task){
        return;
    }

    connect(_task,SIGNAL(started()),this,SLOT(onTaskStarted()));
    connect(_task,SIGNAL(finished()),this,SLOT(onTaskFinished()));
    connect(this,SIGNAL(cancel()),_task,SLOT(cancel()));
}

void SingleLoadingWidget::onTaskStarted()
{
    show();
}

void SingleLoadingWidget::onTaskFinished()
{
    close();
}
