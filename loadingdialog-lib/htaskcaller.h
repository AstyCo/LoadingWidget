#ifndef HTASKCALLER_H
#define HTASKCALLER_H

#include "abstracthtaskcaller.h"
#include "runandwait.h"

#include <QtConcurrentRun>

#include <QDebug>


template <typename T, typename Class, typename Param1, typename Arg1, typename Param2, typename Arg2>
class HTaskCaller : public AbstractHTaskCaller
{
    typename Class * _pInstance;
    typename (Class::*fn)(Param1, Param2) *_pFuncRun;
public:
    HTaskCaller(Class *pInstance, T (Class::*fn)(Param1, Param2), const Arg1 &arg1, const Arg2 &arg2):
        _pInstance(pInstance), _pFuncRun(fn) {}

    void run(bool sync = true){
        if(_pInstance!= NULL && _pFuncRun != NULL){
            qDebug() << "CALL INSTANCE FUNC";
        }
        else{
            qWarning("HTaskCaller:: Instance or Function pointer is NULL");
            return;
        }

        QFuture<T> future = QtConcurrent::run(object,fn,arg1,arg2,arg3);
        if(sync)
            waitWithEventProcessing(future);

    }
};

#endif // HTASKCALLER_H
