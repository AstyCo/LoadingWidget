#ifndef HTASKEXTENSION_H
#define HTASKEXTENSION_H

#include "loadingdialog_global.h"
#include "htaskcaller.h"
#include "htaskbreaker.h"

template <typename T, typename Class, typename Param1, typename Arg1, typename Param2, typename Arg2>
HTaskCaller<T,Class,Param1,Arg1,Param2,Arg2> * makeCaller(Class *pInstance,
                        T (Class::*fn)(Param1, Param2),
                        const Arg1 &arg1,
                        const Arg2 &arg2){
    return new HTaskCaller<T,Class,Param1,Arg1,Param2,Arg2>(pInstance,fn,arg1,arg2);
}

template <typename T, typename Class, typename Param1, typename Arg1, typename Param2, typename Arg2>
HTaskBreaker<T,Class,Param1,Arg1,Param2,Arg2> * makeBreaker(Class *pInstance,
                        T (Class::*fn)(Param1, Param2),
                        const Arg1 &arg1,
                        const Arg2 &arg2){
    return new HTaskBreaker<T,Class,Param1,Arg1,Param2,Arg2>(pInstance,fn,arg1,arg2);
}

template <typename T, typename Class>
HTaskBreaker<T,Class> * makeBreaker(Class *pInstance,T (Class::*fn)()){
    return new HTaskBreaker<T,Class>(pInstance,fn);
}


#endif // HTASKEXTENSION_H
