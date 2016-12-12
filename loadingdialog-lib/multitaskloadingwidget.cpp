#include "ui_multitaskloadingwidget.h"
#include "multitaskloadingwidget.h"

MultiTaskLoadingWidget::MultiTaskLoadingWidget(QWidget *parent, Qt::WindowFlags fl) :
    QWidget(parent,fl)
{

}

MultiTaskLoadingWidget::~MultiTaskLoadingWidget()
{
    if(parentWidget())
        parentWidget()->setEnabled(true);
}

void MultiTaskLoadingWidget::init()
{
    ui->setupUi(this);

    setWindowModality(Qt::ApplicationModal);
    setAttribute(Qt::WA_DeleteOnClose, true);
    setWindowFlags( Qt::SubWindow | Qt::Dialog | Qt::WindowTitleHint | Qt::WindowStaysOnTopHint);

    // center on parent
    if(parentWidget()!= NULL)
    {
        QPoint dialogCenter = mapToGlobal(rect().center());
        QPoint parentWindowCenter = parentWidget()->window()->mapToGlobal(
            parentWidget()->window()->rect().center());

        move(parentWindowCenter - dialogCenter);
        parentWidget()->setEnabled(false);
    }

    _manager = NULL;
}

void MultiTaskLoadingWidget::onTaskAdded(HTask *task)
{

}

void MultiTaskLoadingWidget::onTaskRemoved(HTask *task)
{

}

HTaskManager *MultiTaskLoadingWidget::manager() const
{
    return _manager;
}

void MultiTaskLoadingWidget::setManager(HTaskManager *manager)
{
    if(manager == NULL)
        return;

    if(_manager!= NULL)
    {

    }
    _manager = manager;
    {
        connect(_manager, SIGNAL(taskAdded(HTask*)), this, SLOT(onT)
    }
}
