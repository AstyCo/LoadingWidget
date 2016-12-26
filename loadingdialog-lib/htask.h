#ifndef HTASK_H
#define HTASK_H

#include "loadingdialog_global.h"

#include "abstracthtaskcaller.h"
#include "abstracthtaskbreaker.h"

#include <QObject>
#include <QString>

class LOADINGDIALOGSHARED_EXPORT HTask: public QObject
{
    Q_OBJECT

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
    void wait(bool eventProcessing = true);
    bool cancelable() const;

    QString title() const;
    void setTitle(const QString &title);

public slots:
    void run();
    void cancel();
signals:
    void started();
    void finished();
    void paused();
    void resumed();

private:
    bool _canceled;
    QString _title;

    AbstractHTaskCaller *_pCaller;
    AbstractHTaskBreaker *_pBreaker;

};





#endif // HTASK_H
