#ifndef ABSTRACTHTASKCANCEALER_H
#define ABSTRACTHTASKCANCEALER_H


class AbstractHTaskCancealer
{
public:
    AbstractHTaskCancealer();
    virtual ~AbstractHTaskCancealer() { }

    virtual void cancel() = 0;
};

#endif // ABSTRACTHTASKCANCEALER_H
