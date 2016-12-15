#include "myclass.h"

#ifdef Q_OS_WIN
#include <windows.h> // for Sleep
#endif
void mySleep(int ms)
{
//    QTEST_ASSERT(ms > 0);

#ifdef Q_OS_WIN
    Sleep(uint(ms));
#else
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, NULL);
#endif
}

MyClass::MyClass(){}

void MyClass::hardComputationFunction(unsigned int start, long len){
    _stop = false;
    for(long long i=start;i<len;){
        mySleep(50);
        qDebug() << "YOOLOO: "<< i;
        ++i;
        if(_stop)
            break;
    }
}

void MyClass::cancelComputations()
{
    _stop = true;
}
