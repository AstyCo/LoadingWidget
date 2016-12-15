#ifndef HTASKCALLER_H
#define HTASKCALLER_H

#include "abstracthtaskcaller.h"
#include "runandwaitsingleton.h"

#include <QtConcurrentRun>

#include <QDebug>

template <typename T, typename Class, typename Param1, typename Arg1, typename Param2, typename Arg2>
class HTaskCaller : public AbstractHTaskCaller
{
    QFuture<T> _future;
    Class * _pInstance;
    T (Class::*_pFuncRun)(Param1, Param2);
    Arg1 _arg1;
    Arg2 _arg2;
public:
    HTaskCaller(Class *pInstance, T (Class::*fn)(Param1, Param2), const Arg1 &arg1, const Arg2 &arg2):
        _pInstance(pInstance),
        _pFuncRun(fn),
        _arg1(arg1),
        _arg2(arg2)
    { }

    void run(){
        if(_pInstance!= NULL && _pFuncRun != NULL){
            _future = QtConcurrent::run(_pInstance,_pFuncRun,_arg1,_arg2);
        }
        else{
            qWarning("HTaskCaller:: Instance or Function pointer is NULL");
            return;
        }
    }
    void wait(bool eventProcessing = true){
        if(eventProcessing)
            waitWithEventProcessing(_future);
        else
            _future.waitForFinished();
    }

    bool isRunning() const{
        return _future.isRunning();
    }

    // return values
    T result() const {
        return _future.result();
    }
    T resultAt(int index) const {
        return _future.resultAt(index);
    }
};

#endif // HTASKCALLER_H
