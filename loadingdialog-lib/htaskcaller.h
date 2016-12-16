#ifndef HTASKCALLER_H
#define HTASKCALLER_H

#include "abstracthtaskcaller.h"
#include "runandwait.h"

#include <QtConcurrentRun>
#include <QFutureWatcher>
#include <QDebug>

template <typename ...> class HTaskCaller;

/// Class member : 0 arg
template <typename T, typename Class>
class HTaskCaller<T,Class> : public AbstractHTaskCaller
{
    QFuture<T> _future;
    QFutureWatcher<T> _futureWatcher;
    Class * _pInstance;
    T (Class::*_pFuncRun)();
public:
    HTaskCaller(Class *pInstance, T (Class::*fn)()):
        _pInstance(pInstance),
        _pFuncRun(fn)
    { }

    void run(){
        if(_pInstance!= NULL && _pFuncRun != NULL){
            _future = QtConcurrent::run(_pInstance,_pFuncRun);
            if(_task)
            {
                _futureWatcher.disconnect(_task);
                QObject::connect(&_futureWatcher,SIGNAL(started()),_task,SIGNAL(started()));
                QObject::connect(&_futureWatcher,SIGNAL(finished()),_task,SIGNAL(finished()));
                _futureWatcher.setFuture(_future);
            }
            else
                qWarning("HTaskCaller::run():: HTask is NULL");
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

/// Class member : 1 arg
template <typename T, typename Class, typename Param1, typename Arg1>
class HTaskCaller<T,Class,Param1,Arg1> : public AbstractHTaskCaller
{
    QFuture<T> _future;
    QFutureWatcher<T> _futureWatcher;
    Class * _pInstance;
    T (Class::*_pFuncRun)(Param1);
    Arg1 _arg1;
public:
    HTaskCaller(Class *pInstance, T (Class::*fn)(Param1), const Arg1 &arg1):
        _pInstance(pInstance),
        _pFuncRun(fn),
        _arg1(arg1)
    { }

    void run(){
        if(_pInstance!= NULL && _pFuncRun != NULL){
            _future = QtConcurrent::run(_pInstance,_pFuncRun,_arg1);
            if(_task)
            {
                _futureWatcher.disconnect(_task);
                QObject::connect(&_futureWatcher,SIGNAL(started()),_task,SIGNAL(started()));
                QObject::connect(&_futureWatcher,SIGNAL(finished()),_task,SIGNAL(finished()));
                _futureWatcher.setFuture(_future);
            }
            else
                qWarning("HTaskCaller::run():: HTask is NULL");
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

/// Class member : 2 arg
template <typename T, typename Class, typename Param1, typename Arg1, typename Param2, typename Arg2>
class HTaskCaller<T,Class,Param1,Arg1,Param2,Arg2> : public AbstractHTaskCaller
{
    QFuture<T> _future;
    QFutureWatcher<T> _futureWatcher;
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
            if(_task)
            {
                _futureWatcher.disconnect(_task);
                QObject::connect(&_futureWatcher,SIGNAL(started()),_task,SIGNAL(started()));
                QObject::connect(&_futureWatcher,SIGNAL(finished()),_task,SIGNAL(finished()));
                _futureWatcher.setFuture(_future);
            }
            else
                qWarning("HTaskCaller::run():: HTask is NULL");
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

/// Class member : 3 arg
template <typename T, typename Class, typename Param1, typename Arg1, typename Param2, typename Arg2
          , typename Param3, typename Arg3>
class HTaskCaller<T,Class,Param1,Arg1,Param2,Arg2,Param3,Arg3> : public AbstractHTaskCaller
{
    QFuture<T> _future;
    QFutureWatcher<T> _futureWatcher;
    Class * _pInstance;
    T (Class::*_pFuncRun)(Param1, Param2, Param3);
    Arg1 _arg1;
    Arg2 _arg2;
    Arg3 _arg3;
public:
    HTaskCaller(Class *pInstance, T (Class::*fn)(Param1, Param2, Param3)
                , const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3):
        _pInstance(pInstance),
        _pFuncRun(fn),
        _arg1(arg1),
        _arg2(arg2),
        _arg3(arg3)
    { }

    void run(){
        if(_pInstance!= NULL && _pFuncRun != NULL){
            _future = QtConcurrent::run(_pInstance,_pFuncRun,_arg1,_arg2,_arg3);
            if(_task)
            {
                _futureWatcher.disconnect(_task);
                QObject::connect(&_futureWatcher,SIGNAL(started()),_task,SIGNAL(started()));
                QObject::connect(&_futureWatcher,SIGNAL(finished()),_task,SIGNAL(finished()));
                _futureWatcher.setFuture(_future);
            }
            else
                qWarning("HTaskCaller::run():: HTask is NULL");
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

/// Class member : 4 arg
template <typename T, typename Class, typename Param1, typename Arg1, typename Param2, typename Arg2
          , typename Param3, typename Arg3, typename Param4, typename Arg4>
class HTaskCaller<T,Class,Param1,Arg1,Param2,Arg2,Param3,Arg3,Param4,Arg4> : public AbstractHTaskCaller
{
    QFuture<T> _future;
    QFutureWatcher<T> _futureWatcher;
    Class * _pInstance;
    T (Class::*_pFuncRun)(Param1, Param2, Param3, Param4);
    Arg1 _arg1;
    Arg2 _arg2;
    Arg3 _arg3;
    Arg4 _arg4;
public:
    HTaskCaller(Class *pInstance, T (Class::*fn)(Param1, Param2, Param3, Param4)
                , const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3
                , const Arg4 &arg4):
        _pInstance(pInstance),
        _pFuncRun(fn),
        _arg1(arg1),
        _arg2(arg2),
        _arg3(arg3),
        _arg4(arg4)
    { }

    void run(){
        if(_pInstance!= NULL && _pFuncRun != NULL){
            _future = QtConcurrent::run(_pInstance,_pFuncRun,_arg1,_arg2,_arg3,_arg4);
            if(_task)
            {
                _futureWatcher.disconnect(_task);
                QObject::connect(&_futureWatcher,SIGNAL(started()),_task,SIGNAL(started()));
                QObject::connect(&_futureWatcher,SIGNAL(finished()),_task,SIGNAL(finished()));
                _futureWatcher.setFuture(_future);
            }
            else
                qWarning("HTaskCaller::run():: HTask is NULL");
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

/// Class member : 5 arg
template <typename T, typename Class, typename Param1, typename Arg1, typename Param2, typename Arg2
          , typename Param3, typename Arg3, typename Param4, typename Arg4, typename Param5, typename Arg5>
class HTaskCaller<T,Class,Param1,Arg1,Param2,Arg2,Param3,Arg3,Param4,Arg4,Param5,Arg5> : public AbstractHTaskCaller
{
    QFuture<T> _future;
    QFutureWatcher<T> _futureWatcher;
    Class * _pInstance;
    T (Class::*_pFuncRun)(Param1, Param2, Param3, Param4, Param5);
    Arg1 _arg1;
    Arg2 _arg2;
    Arg3 _arg3;
    Arg4 _arg4;
    Arg5 _arg5;
public:
    HTaskCaller(Class *pInstance, T (Class::*fn)(Param1, Param2, Param3, Param4, Param5)
                , const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3
                , const Arg4 &arg4, const Arg5 &arg5):
        _pInstance(pInstance),
        _pFuncRun(fn),
        _arg1(arg1),
        _arg2(arg2),
        _arg3(arg3),
        _arg4(arg4),
        _arg5(arg5)
    { }

    void run(){
        if(_pInstance!= NULL && _pFuncRun != NULL){
            _future = QtConcurrent::run(_pInstance,_pFuncRun,_arg1,_arg2,_arg3,_arg4,_arg5);
            if(_task)
            {
                _futureWatcher.disconnect(_task);
                QObject::connect(&_futureWatcher,SIGNAL(started()),_task,SIGNAL(started()));
                QObject::connect(&_futureWatcher,SIGNAL(finished()),_task,SIGNAL(finished()));
                _futureWatcher.setFuture(_future);
            }
            else
                qWarning("HTaskCaller::run():: HTask is NULL");
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
