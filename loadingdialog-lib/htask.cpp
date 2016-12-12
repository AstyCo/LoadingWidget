#include "htask.h"

QString HTask::title() const
{
    return _title;
}

void HTask::setTitle(const QString &taskName)
{
    _title = taskName;
}

void HTask::run(bool sync){
    if(_pCaller!= NULL)
    {
        _pCaller->run(sync);
    }
    else
    {
        qWarning("HTask:: Trying to Run task without instance of HTaskCaller");
        return;
    }
}

void HTask::cancel(){
    if(_pCancealer!= NULL)
    {
        _pCancealer->cancel();
    }
    else
    {
        qWarning("HTask:: Trying to Cancel task without instance of HTaskCancealer");
        return;
    }
}
