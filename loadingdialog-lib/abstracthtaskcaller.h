#ifndef ABSTRACTHTASKCALLER_H
#define ABSTRACTHTASKCALLER_H

#include "loadingdialog_global.h"

class LOADINGDIALOGSHARED_EXPORT AbstractHTaskCaller
{
public:
    AbstractHTaskCaller();
    virtual ~AbstractHTaskCaller() { }

    virtual void run() = 0;
    virtual void wait(bool eventProcessing) = 0;
    virtual bool isRunning() const = 0;
};

#endif // ABSTRACTHTASKCALLER_H
