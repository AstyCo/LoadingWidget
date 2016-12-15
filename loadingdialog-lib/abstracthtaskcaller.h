#ifndef ABSTRACTHTASKCALLER_H
#define ABSTRACTHTASKCALLER_H

#include "loadingdialog_global.h"

class HTask;

class LOADINGDIALOGSHARED_EXPORT AbstractHTaskCaller
{
protected:
    HTask *_task;
public:
    AbstractHTaskCaller();
    virtual ~AbstractHTaskCaller() { }

    virtual void run() = 0;
    virtual void wait(bool eventProcessing) = 0;
    virtual bool isRunning() const = 0;

    HTask *task() const;
    void setTask(HTask *task);
};

#endif // ABSTRACTHTASKCALLER_H
