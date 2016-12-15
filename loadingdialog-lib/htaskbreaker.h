#ifndef HTASKBREAKER_H
#define HTASKBREAKER_H

#include "abstracthtaskbreaker.h"
#include <QtConcurrentRun>

template <typename...> class HTaskBreaker;

template <typename T, typename Class>
class HTaskBreaker<T,Class> : public AbstractHTaskBreaker
{
    QFuture<T> _future;
    Class * _pInstance;
    T (Class::*_pFuncCancel)();
public:
    HTaskBreaker(Class *pInstance, T (Class::*fn)()):
        _pInstance(pInstance),
        _pFuncCancel(fn)
    { }

    void cancel(){
        if(_pInstance!= NULL && _pFuncCancel != NULL){
            _future = QtConcurrent::run(_pInstance,_pFuncCancel);
        }
        else{
            qWarning("HTaskCancealer:: Instance or Function pointer is NULL");
            return;
        }
    }

    void wait(bool eventProcessing = true){
        if(eventProcessing)
            waitWithEventProcessing(_future);
        else
            _future.waitForFinished();
    }
    // return values
    T result() const {
        return _future.result();
    }
    T resultAt(int index) const {
        return _future.resultAt(index);
    }
};



template <typename T, typename Class, typename Param1, typename Arg1, typename Param2, typename Arg2>
class HTaskBreaker<T,Class,Param1,Arg1,Param2,Arg2> : public AbstractHTaskBreaker
{
    QFuture<T> _future;
    Class * _pInstance;
    T (Class::*_pFuncCancel)(Param1, Param2);
    Arg1 _arg1;
    Arg2 _arg2;
public:
    HTaskBreaker(Class *pInstance, T (Class::*fn)(Param1, Param2), const Arg1 &arg1, const Arg2 &arg2):
        _pInstance(pInstance),
        _pFuncCancel(fn),
        _arg1(arg1),
        _arg2(arg2)
    { }

    void cancel(){
        if(_pInstance!= NULL && _pFuncCancel != NULL){
            _future = QtConcurrent::run(_pInstance,_pFuncCancel,_arg1,_arg2);
        }
        else{
            qWarning("HTaskCancealer:: Instance or Function pointer is NULL");
            return;
        }
    }

    void wait(bool eventProcessing = true){
        if(eventProcessing)
            waitWithEventProcessing(_future);
        else
            _future.waitForFinished();
    }
    // return values
    T result() const {
        return _future.result();
    }
    T resultAt(int index) const {
        return _future.resultAt(index);
    }
};


#endif // HTASKBREAKER_H
