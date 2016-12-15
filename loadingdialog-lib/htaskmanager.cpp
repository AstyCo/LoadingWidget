#include "htaskmanager.h"

#include <QDebug>

HTaskManager::HTaskManager()
    : _mode(synchronous),_currentTask(NULL) {
    connect(this,SIGNAL(taskStarted(HTask*)),this,SLOT(setCurrentTask(HTask*)));
    connect(this,SIGNAL(taskFinished(HTask*)),this,SLOT(clearCurrentTask()));
}

void HTaskManager::addTask(HTask *task){
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
    emit started();
    for(int i = 0; i < _tasks.size(); ++i)
    {
        emit taskStarted(_tasks[i]);
        _tasks[i]->run();
        if(_mode == synchronous)
            _tasks[i]->wait();
        emit taskFinished(_tasks[i]);
    }
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

void HTaskManager::setCurrentTask(HTask *task)
{
    if(_currentTask != NULL)
        qWarning("HTaskManager::setCurrentTask:: some task is processed");
    _currentTask = task;
}

void HTaskManager::clearCurrentTask()
{
    _currentTask = NULL;
}
