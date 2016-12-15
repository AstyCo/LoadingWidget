#ifndef ABSTRACTHTASKBREAKER_H
#define ABSTRACTHTASKBREAKER_H

#include "loadingdialog_global.h"

class LOADINGDIALOGSHARED_EXPORT AbstractHTaskBreaker
{
public:
    AbstractHTaskBreaker();
    virtual ~AbstractHTaskBreaker() { }

    virtual void cancel() = 0;
};

#endif // ABSTRACTHTASKBREAKER_H
