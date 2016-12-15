#ifndef HTASKBREAKER_H
#define HTASKBREAKER_H

#include "abstracthtaskbreaker.h"
#include <QtConcurrentRun>

template <typename...> class HTaskBreaker;

/// Class member : 0 arg
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

/// Class member : 1 arg
template <typename T, typename Class, typename Param1, typename Arg1>
class HTaskBreaker<T,Class,Param1,Arg1> : public AbstractHTaskBreaker
{
    QFuture<T> _future;
    Class * _pInstance;
    T (Class::*_pFuncCancel)(Param1);
    Arg1 _arg1;
public:
    HTaskBreaker(Class *pInstance, T (Class::*fn)(Param1), const Arg1 &arg1):
        _pInstance(pInstance),
        _pFuncCancel(fn),
        _arg1(arg1)
    { }

    void cancel(){
        if(_pInstance!= NULL && _pFuncCancel != NULL){
            _future = QtConcurrent::run(_pInstance,_pFuncCancel,_arg1);
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

/// Class member : 2 arg
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

/// Class member : 3 arg
template <typename T, typename Class, typename Param1, typename Arg1
          , typename Param2, typename Arg2, typename Param3, typename Arg3>
class HTaskBreaker<T,Class,Param1,Arg1,Param2,Arg2,Param3,Arg3> : public AbstractHTaskBreaker
{
    QFuture<T> _future;
    Class * _pInstance;
    T (Class::*_pFuncCancel)(Param1, Param2, Param3);
    Arg1 _arg1;
    Arg2 _arg2;
    Arg3 _arg3;

public:
    HTaskBreaker(Class *pInstance, T (Class::*fn)(Param1, Param2, Param3)
                 , const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3):
        _pInstance(pInstance),
        _pFuncCancel(fn),
        _arg1(arg1),
        _arg2(arg2),
        _arg3(arg3)
    { }

    void cancel(){
        if(_pInstance!= NULL && _pFuncCancel != NULL){
            _future = QtConcurrent::run(_pInstance,_pFuncCancel,_arg1,_arg2,_arg3);
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

/// Class member : 4 arg
template <typename T, typename Class, typename Param1, typename Arg1
          , typename Param2, typename Arg2, typename Param3, typename Arg3
          , typename Param4, typename Arg4>
class HTaskBreaker<T,Class
        ,Param1,Arg1,Param2,Arg2,Param3,Arg3,Param4,Arg4>
        : public AbstractHTaskBreaker
{
    QFuture<T> _future;
    Class * _pInstance;
    T (Class::*_pFuncCancel)(Param1, Param2, Param3, Param4);
    Arg1 _arg1;
    Arg2 _arg2;
    Arg3 _arg3;
    Arg4 _arg4;

public:
    HTaskBreaker(Class *pInstance, T (Class::*fn)(Param1, Param2, Param3, Param4)
                 , const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3, const Arg4 &arg4):
        _pInstance(pInstance),
        _pFuncCancel(fn),
        _arg1(arg1),
        _arg2(arg2),
        _arg3(arg3),
        _arg4(arg4)
    { }

    void cancel(){
        if(_pInstance!= NULL && _pFuncCancel != NULL){
            _future = QtConcurrent::run(_pInstance,_pFuncCancel,_arg1,_arg2,_arg3,_arg4);
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

/// Class member : 5 arg
template <typename T, typename Class, typename Param1, typename Arg1
          , typename Param2, typename Arg2, typename Param3, typename Arg3
          , typename Param4, typename Arg4, typename Param5, typename Arg5>
class HTaskBreaker<T,Class
        ,Param1,Arg1,Param2,Arg2,Param3,Arg3,Param4,Arg4,Param5,Arg5>
        : public AbstractHTaskBreaker
{
    QFuture<T> _future;
    Class * _pInstance;
    T (Class::*_pFuncCancel)(Param1, Param2, Param3, Param4, Param5);
    Arg1 _arg1;
    Arg2 _arg2;
    Arg3 _arg3;
    Arg4 _arg4;
    Arg5 _arg5;

public:
    HTaskBreaker(Class *pInstance, T (Class::*fn)(Param1, Param2, Param3, Param4, Param5)
                 , const Arg1 &arg1, const Arg2 &arg2
                 , const Arg3 &arg3, const Arg4 &arg4, const Arg4 &arg5):
        _pInstance(pInstance),
        _pFuncCancel(fn),
        _arg1(arg1),
        _arg2(arg2),
        _arg3(arg3),
        _arg4(arg4),
        _arg5(arg5)
    { }

    void cancel(){
        if(_pInstance!= NULL && _pFuncCancel != NULL){
            _future = QtConcurrent::run(_pInstance,_pFuncCancel,_arg1,_arg2,_arg3,_arg4,_arg5);
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
