#include "htaskmanager.h"
#include "multitaskloadingwidget.h"
#include "singleloadingwidget.h"

#include <QApplication>
#include <QDebug>

HTaskManager::HTaskManager(SynchronizationMode mode)
    : _mode(mode)
{
    init();
}

HTaskManager::HTaskManager(HTask *task, QWidget *parentWidget, const QString &title, const QString &description, HTaskManager::SynchronizationMode mode)
    : _mode(mode)
{
    init();
    _title = title;
    _description = description;
    _parentWidget = parentWidget;

    addTask(task);
}

HTaskManager::HTaskManager( QWidget *parentWidget,
            const QString &title,
            const QString &description,
            HTaskManager::SynchronizationMode mode)
    : _mode(mode)
{
    init();
    _title = title;
    _description = description;
    _parentWidget = parentWidget;
}

void HTaskManager::addTask(HTask *task){
    connect(task,SIGNAL(started()),this,SLOT(onTaskStarted()));
    connect(task,SIGNAL(finished()),this,SLOT(onTaskFinished()));
//    connect(task,SIGNAL(paused()),this,SLOT(onTaskPaused()));
//    connect(task,SIGNAL(resumed()),this,SLOT(onTaskResumed()));


    _tasks.append(task);
    emit taskAdded(task);
}

void HTaskManager::removeTask(HTask *task){
    _tasks.removeAll(task);
    emit taskRemoved(task);
}

HTask *HTaskManager::task(const QString &taskTitle){
    foreach(HTask *task, _tasks)
        if(task->title() == taskTitle)
            return task;
    // not found
    return NULL;
}

void HTaskManager::run(){
    if(_tasks.empty())
        return;

    QApplication::processEvents(); // calls all delayed [deleteLater]
    if(!_widget)
        initWidget(); // Initialize default MultiTaskLoadingWidget

    initTasks();
    initRun();
    for(int i = 0; i < _tasks.size(); ++i)
    {
        _tasks[i]->run();
        if(_mode == sync)
            _tasks[i]->wait();
    }
    startWaiting();
}

const QList<HTask *>& HTaskManager::tasks() const
{
    return _tasks;
}

void HTaskManager::cancelRuns()
{
    foreach(HTask *task, _tasks)
        task->cancel();
}

void HTaskManager::initTasks()
{
    foreach(HTask *task, _tasks)
        task->init();
}

void HTaskManager::initRun()
{
    _anyTaskStarted = false;
    _waiting = false;
    emit started();
}

void HTaskManager::startWaiting()
{
    _waiting = true;
    for(;;){
        if(isFinished())
            return;
        QApplication::processEvents();
    }
}

bool HTaskManager::isFinished()
{
    if(_waiting && _anyTaskStarted && _runningTasks.isEmpty()){
        emit finished();
        return true;
    }
    return false;
}

void HTaskManager::onTaskStarted()
{
    HTask *task = dynamic_cast<HTask*>(sender());
    if(!task){
        qWarning("HTaskManager::onTaskStarted():: HTask is NULL");
        return;
    }
    _runningTasks.append(task);
    _anyTaskStarted = true;
    emit taskStarted(task);
}

void HTaskManager::onTaskFinished()
{
    HTask *task = dynamic_cast<HTask*>(sender());
    if(!task){
        qWarning("HTaskManager::onTaskStarted():: HTask is NULL");
        return;
    }
    _runningTasks.removeOne(task);
    emit taskFinished(task);
    isFinished();
}

void HTaskManager::setPlayMode(LoadingDialog::PlayMode playMode)
{
    _playMode = playMode;
}

//void HTaskManager::onTaskPaused()
//{
//    HTask *task = dynamic_cast<HTask*>(sender());
//    if(!task){
//        qWarning("HTaskManager::onTaskStarted():: HTask is NULL");
//        return;
//    }
//    qDebug() << "task PAUSED "<< task->title();
//}

//void HTaskManager::onTaskResumed()
//{
//    HTask *task = dynamic_cast<HTask*>(sender());
//    if(!task){
//        qWarning("HTaskManager::onTaskStarted():: HTask is NULL");
//        return;
//    }
//    qDebug() << "task RESUMED "<< task->title();
//}

QWidget *HTaskManager::widget() const
{
    return _widget.data();
}

void HTaskManager::setWidget(const QPointer<QWidget> &widget)
{
    _widget = widget;
}

HTaskManager::SynchronizationMode HTaskManager::mode() const
{
    return _mode;
}

void HTaskManager::setMode(const SynchronizationMode &mode)
{
    _mode = mode;
}

void HTaskManager::init()
{
    _widget = NULL;
    _playMode = LoadingDialog::modeUnlimitted;
}

void HTaskManager::initWidget()
{
    if(_widget)
        qWarning("HTaskManager::initWidget:: _widget not NULL");

    if(_tasks.size() == 1)
        _widget = new SingleLoadingWidget(
                    _tasks[0],this,_title,_description,_playMode,_parentWidget);
    else
        _widget = new MultiTaskLoadingWidget(
                    this,_title,_description,_parentWidget);
}
