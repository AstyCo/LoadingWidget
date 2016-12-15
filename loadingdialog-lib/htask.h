#ifndef HTASK_H
#define HTASK_H

#include "loadingdialog_global.h"

#include "abstracthtaskcaller.h"
#include "abstracthtaskbreaker.h"


#include <QString>

class LOADINGDIALOGSHARED_EXPORT HTask
{
    bool _canceled;
    QString _title;

    AbstractHTaskCaller *_pCaller;
    AbstractHTaskBreaker *_pBreaker;

public:
    HTask(AbstractHTaskCaller *pCaller,const QString &title):
        _title(title),_pCaller(pCaller), _pBreaker(NULL) {
        init();
    }
    HTask(AbstractHTaskCaller *pCaller, AbstractHTaskBreaker *pBreaker,const QString &title):
        _title(title),_pCaller(pCaller), _pBreaker(pBreaker) {
        init();
    }

    void init();
    void run();
    void wait(bool eventProcessing = true);
    void cancel();
    bool cancelable() const;

    QString title() const;
    void setTitle(const QString &title);
};





#endif // HTASK_H
