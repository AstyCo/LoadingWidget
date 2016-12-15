#include "htaskmanager.h"

#include <QDebug>

HTaskManager::HTaskManager(SynchronizationMode mode)
    : _mode(mode) {
}

void HTaskManager::addTask(HTask *task){
    connect(task,SIGNAL(started()),this,SLOT(onTaskStarted()));
    connect(task,SIGNAL(finished()),this,SLOT(onTaskFinished()));

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
    checkForFinished();
}

void HTaskManager::checkForFinished()
{
    if(_waiting && _anyTaskStarted && _runningTasks.isEmpty())
        emit finished();
}

void HTaskManager::onTaskStarted()
{
    HTask *task = dynamic_cast<HTask*>(sender());
    if(!task){
        qWarning("HTaskManager::onTaskStarted():: HTask is NULL");
        return;
    }
    _anyTaskStarted = true;
    _runningTasks.append(task);
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
    checkForFinished();
}

HTaskManager::SynchronizationMode HTaskManager::mode() const
{
    return _mode;
}

void HTaskManager::setMode(const SynchronizationMode &mode)
{
    _mode = mode;
}
