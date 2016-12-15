#ifndef RUNANDWAITSINGLETON_H
#define RUNANDWAITSINGLETON_H

#include <QDialog>
#include <QApplication>
#include <QtConcurrentRun>
#include "loadingdialog.h"
#include "loadingdialogsingleton.h"

template <typename T>
void waitWithEventProcessing(QFuture<T> &future)
{
    for(;;){
        if(future.isFinished())
            break;
        QApplication::processEvents();
    }
}

template <typename T, typename Class>
void runAndWait( Class *object, T (Class::*fn)())
{
    LoadingDialog dlg(
                LoadingDialogSingleton::activeWindow());
    LoadingDialogSingleton::setLoadingDialog(&dlg);
    dlg.show();
    QFuture<T> future = QtConcurrent::run(object,fn);
    waitWithEventProcessing(future);
    dlg.close();
}

template <typename T, typename Class, typename Param1, typename Arg1>
void runAndWait( Class *object, T (Class::*fn)(Param1), const Arg1 &arg1)
{
    LoadingDialog dlg(
                LoadingDialogSingleton::activeWindow());
    LoadingDialogSingleton::setLoadingDialog(&dlg);
    dlg.show();
    QFuture<T> future = QtConcurrent::run(object,fn,arg1);
    waitWithEventProcessing(future);
    dlg.close();
}

template <typename T, typename Class, typename Param1, typename Arg1, typename Param2, typename Arg2>
void runAndWait( Class *object, T (Class::*fn)(Param1, Param2), const Arg1 &arg1, const Arg2 &arg2)
{
    LoadingDialog dlg(
                LoadingDialogSingleton::activeWindow());
    LoadingDialogSingleton::setLoadingDialog(&dlg);
    dlg.show();
    QFuture<T> future = QtConcurrent::run(object,fn,arg1,arg2);
    waitWithEventProcessing(future);
    dlg.close();
}

template <typename T, typename Class, typename Param1, typename Arg1, typename Param2, typename Arg2, typename Param3, typename Arg3>
void runAndWait( Class *object, T (Class::*fn)(Param1, Param2, Param3), const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3)
{
    LoadingDialog dlg(
                LoadingDialogSingleton::activeWindow());
    LoadingDialogSingleton::setLoadingDialog(&dlg);
    dlg.show();
    QFuture<T> future = QtConcurrent::run(object,fn,arg1,arg2,arg3);
    waitWithEventProcessing(future);
    dlg.close();
}

template <typename T, typename Class, typename Param1, typename Arg1, typename Param2, typename Arg2, typename Param3, typename Arg3, typename Param4, typename Arg4>
void runAndWait( Class *object, T (Class::*fn)(Param1, Param2, Param3, Param4), const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3, const Arg4 &arg4)
{
    LoadingDialog dlg(
                LoadingDialogSingleton::activeWindow());
    LoadingDialogSingleton::setLoadingDialog(&dlg);
    dlg.show();
    QFuture<T> future = QtConcurrent::run(object,fn,arg1,arg2,arg3,arg4);
    waitWithEventProcessing(future);
    dlg.close();
}

template <typename T, typename Class, typename Param1, typename Arg1, typename Param2, typename Arg2, typename Param3, typename Arg3, typename Param4, typename Arg4, typename Param5, typename Arg5>
void runAndWait( Class *object, T (Class::*fn)(Param1, Param2, Param3, Param4, Param5), const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3, const Arg4 &arg4, const Arg5 &arg5)
{
    LoadingDialog dlg(
                LoadingDialogSingleton::activeWindow());
    LoadingDialogSingleton::setLoadingDialog(&dlg);
    dlg.show();
    QFuture<T> future = QtConcurrent::run(object,fn,arg1,arg2,arg3,arg4,arg5);
    waitWithEventProcessing(future);
    dlg.close();
}



#endif // RUNANDWAITSINGLETON_H
