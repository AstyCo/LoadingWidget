#ifndef MYCLASS_H
#define MYCLASS_H

//#include <qtestassert.h>
#include <QDebug>

void mySleep(int ms);


class MyClass
{
public:
    MyClass();

    void hardComputationFunction(unsigned int start, long len);
    void cancelComputations();

private:
    bool _stop;
};

#endif // MYCLASS_H
