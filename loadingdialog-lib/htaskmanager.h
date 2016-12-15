#ifndef HTASKMANAGER_H
#define HTASKMANAGER_H

#include "loadingdialog_global.h"
#include "htask.h"

#include <QObject>
#include <QList>

class LOADINGDIALOGSHARED_EXPORT HTaskManager : public QObject
{
    Q_OBJECT
public:
    enum SynchronizationMode{
        synchronous,
        asynchronous
    };

    HTaskManager();

    void addTask(HTask *task);
    void removeTask(HTask *task);
    HTask *task(const QString &taskTitle);

    void run();
    const QList<HTask *>& tasks() const;
    void cancelRuns();

private:
    void initTasks();
private slots:
    void setCurrentTask(HTask *task);
    void clearCurrentTask();

signals:
    void started();
    void taskStarted(HTask *task);
    void taskFinished(HTask *task);
    void taskAdded(HTask *task);
    void taskRemoved(HTask *task);

private:
    SynchronizationMode _mode;
    QList<HTask*> _tasks;
    HTask *_currentTask;
    bool _cancelable;
};

#endif // HTASKMANAGER_H
