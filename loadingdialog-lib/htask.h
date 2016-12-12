#ifndef HTASK_H
#define HTASK_H

#include "abstracthtaskcaller.h"
#include "abstracthtaskcancealer.h"

#include <QString>

class HTask
{
    QString _title;

    AbstractHTaskCaller *_pCaller;
    AbstractHTaskCancealer *_pCancealer;

public:
    HTask(AbstractHTaskCaller *pCaller):
        _pCaller(pCaller), _pCancealer(NULL) {}
    HTask(AbstractHTaskCaller *pCaller, AbstractHTaskCancealer *pCancealer):
        _pCaller(pCaller), _pCancealer(pCancealer) {}

    void run(bool sync = true);
    void cancel();

    QString title() const;
    void setTitle(const QString &title);
};





#endif // HTASK_H
