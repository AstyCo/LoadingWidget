#ifndef ABSTRACTHTASKCALLER_H
#define ABSTRACTHTASKCALLER_H


class AbstractHTaskCaller
{
public:
    AbstractHTaskCaller();
    virtual ~AbstractHTaskCaller() { }

    virtual void run() = 0;
};

#endif // ABSTRACTHTASKCALLER_H
