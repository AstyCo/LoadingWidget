#ifndef HTASKEXTENSION_H
#define HTASKEXTENSION_H

#include "loadingdialog_global.h"
#include "htaskcaller.h"
#include "htaskbreaker.h"

/// HTaskCaller: Class member : 0 arg
template <typename T, typename Class>
HTaskCaller< T, Class>
    * makeCaller(   Class *pInstance,
                    T (Class::*fn)())
{
    return new HTaskCaller< T, Class> (pInstance, fn);
}

/// HTaskCaller: Class member : 1 arg
template <typename T, typename Class,
          typename Param1, typename Arg1>
HTaskCaller< T, Class, Param1, Arg1>
    * makeCaller(   Class *pInstance,
                    T (Class::*fn)(Param1),
                    const Arg1 &arg1)
{
    return new HTaskCaller< T, Class, Param1, Arg1> (pInstance, fn, arg1);
}

/// HTaskCaller: Class member : 2 arg
template <typename T, typename Class,
          typename Param1, typename Arg1, typename Param2, typename Arg2>
HTaskCaller< T, Class, Param1, Arg1, Param2, Arg2>
    * makeCaller(   Class *pInstance,
                    T (Class::*fn)(Param1, Param2),
                    const Arg1 &arg1, const Arg2 &arg2)
{
    return new HTaskCaller< T, Class, Param1, Arg1, Param2, Arg2> (pInstance, fn, arg1, arg2);
}

/// HTaskCaller: Class member : 3 arg
template <typename T, typename Class,
          typename Param1, typename Arg1, typename Param2, typename Arg2,
          typename Param3, typename Arg3>
HTaskCaller< T, Class, Param1, Arg1, Param2, Arg2, Param3, Arg3>
    * makeCaller(   Class *pInstance,
                    T (Class::*fn)(Param1, Param2, Param3),
                    const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3)
{
    return new HTaskCaller< T, Class, Param1, Arg1,
                            Param2, Arg2, Param3, Arg3> (pInstance, fn, arg1, arg2, arg3);
}

/// HTaskCaller: Class member : 4 arg
template <typename T, typename Class,
          typename Param1, typename Arg1, typename Param2, typename Arg2,
          typename Param3, typename Arg3, typename Param4, typename Arg4>
HTaskCaller< T, Class, Param1, Arg1, Param2, Arg2, Param3, Arg3, Param4, Arg4>
    * makeCaller(   Class *pInstance,
                    T (Class::*fn)(Param1, Param2, Param3, Param4),
                    const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3,
                    const Arg4 &arg4)
{
    return new HTaskCaller< T, Class, Param1, Arg1, Param2, Arg2,
                            Param3, Arg3, Param4, Arg4> (pInstance, fn, arg1, arg2, arg3, arg4);
}

/// HTaskCaller: Class member : 5 arg
template <typename T, typename Class,
          typename Param1, typename Arg1, typename Param2, typename Arg2,
          typename Param3, typename Arg3, typename Param4, typename Arg4,
          typename Param5, typename Arg5>
HTaskCaller< T, Class, Param1, Arg1, Param2, Arg2, Param3, Arg3, Param4, Arg4, Param5, Arg5>
    * makeCaller(   Class *pInstance,
                    T (Class::*fn)(Param1, Param2, Param3, Param4, Param5),
                    const Arg1 &arg1, const Arg2 &arg2, const Arg3 &arg3,
                    const Arg4 &arg4, const Arg5 &arg5)
{
    return new HTaskCaller< T, Class, Param1, Arg1, Param2, Arg2,
                            Param3, Arg3, Param4, Arg4, Param5, Arg5> (pInstance, fn, arg1, arg2, arg3, arg4, arg5);
}


//template <typename T, typename Class, typename Param1, typename Arg1, typename Param2, typename Arg2>
//HTaskBreaker< T,Class,Param1,Arg1,Param2,Arg2>
//    * makeBreaker(  Class *pInstance,
//                    T (Class::*fn)(Param1, Param2),
//                    const Arg1 &arg1,
//                    const Arg2 &arg2)
//{
//    return new HTaskBreaker< T,Class,Param1,Arg1,Param2,Arg2> (pInstance,fn,arg1,arg2);
//}


/// HTaskBeaker: Class member : 0 arg
template <typename T, typename Class>
HTaskBreaker< T, Class>
    * makeBreaker( Class *pInstance,
                   T (Class::*fn)())
{
    return new HTaskBreaker< T, Class> (pInstance, fn);
}


#endif // HTASKEXTENSION_H
