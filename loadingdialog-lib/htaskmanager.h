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
        sync,
        async
    };

    HTaskManager(SynchronizationMode mode = sync);

    void addTask(HTask *task);
    void removeTask(HTask *task);
    HTask *task(const QString &taskTitle);

    void run();
    const QList<HTask *>& tasks() const;
    void cancelRuns();

    SynchronizationMode mode() const;
    void setMode(const SynchronizationMode &mode);

private:
    void initTasks();
    void initRun();
    void startWaiting();
    void checkForFinished();
private slots:
    void onTaskStarted();
    void onTaskFinished();

signals:
    void started();
    void finished();
    void taskStarted(HTask *task);
    void taskFinished(HTask *task);
    void taskAdded(HTask *task);
    void taskRemoved(HTask *task);

private:
    SynchronizationMode _mode;
    QList<HTask*> _runningTasks;
    QList<HTask*> _tasks;
    bool _cancelable,_waiting,_anyTaskStarted;
};

#endif // HTASKMANAGER_H
