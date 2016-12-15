#include "myclass.h"
#include "htaskextension.h"
#include "htaskmanager.h"

#ifdef Q_OS_WIN
#include <windows.h> // for Sleep
#endif
void mySleep(int ms)
{
    QTEST_ASSERT(ms > 0);

#ifdef Q_OS_WIN
    Sleep(uint(ms));
#else
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, NULL);
#endif
}

MyClass::MyClass(){
    HTaskManager manager;

    manager.addTask(new HTask(makeCaller(this,&MyClass::hardComputationFunction,0,10000)));
}

void MyClass::hardComputationFunction(unsigned int start, long len){
    for(long long i=start;i<len;){
        mySleep(50);
        qDebug() << "YOOLOO: "<< i;
        ++i;
    }
}
