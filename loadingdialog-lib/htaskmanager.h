#ifndef HTASKMANAGER_H
#define HTASKMANAGER_H

#include <QList>
#include "htask.h"

class HTaskManager
{
    enum SynchronizationMode{
        synchronous,
        asynchronous
    };

    SynchronizationMode _mode;
    QList<HTask*> _tasks;
public:
    HTaskManager()
        : _mode(synchronous) {}

    void addTask(HTask *task);
    void removeTask(HTask *task);
    HTask *task(const QString &taskTitle);

    void run();
signals:
    void taskStarted(HTask *task);
    void taskFinished(HTask *task);
    void taskAdded(HTask *task);
    void taskRemoved(HTask *task);
};

#endif // HTASKMANAGER_H
