#include "htaskmanager.h"

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
    for(unsigned int i = 0; i < _tasks.size(); ++i)
    {
        emit taskStarted(_tasks[i]);
        _tasks[i]->run(_mode==synchronous);
        emit taskFinished(_tasks[i]);
    }
}
