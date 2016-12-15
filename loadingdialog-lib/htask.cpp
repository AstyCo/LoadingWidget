#include "htask.h"

QString HTask::title() const
{
    return _title;
}

void HTask::setTitle(const QString &taskName)
{
    _title = taskName;
}

void HTask::init()
{
    _canceled = false;
    if(_pCaller)
        _pCaller->setTask(this);
}

void HTask::run(){
    if(_canceled)
        return;

    if(_pCaller!= NULL)
    {
        _pCaller->run();
    }
    else
    {
        qWarning("HTask:: Trying to Run task without instance of HTaskCaller");
        return;
    }
}

void HTask::wait(bool eventProcessing)
{
    if(_pCaller!= NULL)
    {
        _pCaller->wait(eventProcessing);
    }
    else
    {
        qWarning("HTask:: Trying to Wait task without instance of HTaskCaller");
        return;
    }
}

void HTask::cancel(){
    _canceled = true;
    if(_pBreaker!= NULL)
    {
        _pBreaker->cancel();
    }
    else
    {
        qWarning("HTask:: Trying to Cancel task without instance of HTaskCancealer");
        return;
    }
}

bool HTask::cancelable() const
{
    return _pBreaker != NULL;
}
