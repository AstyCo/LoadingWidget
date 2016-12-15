#include "abstracthtaskcaller.h"
#include "htask.h"

HTask *AbstractHTaskCaller::task() const
{
    return _task;
}

void AbstractHTaskCaller::setTask(HTask *task)
{
    _task = task;
}

AbstractHTaskCaller::AbstractHTaskCaller():
    _task(NULL)
{

}
