#ifndef __PLUSOPERATOR_H__
#define __PLUSOPERATOR_H__
#include "PlusOperator.h"

template<class T>
T PlusOperator<T>::operator()(T lhs, T rhs)
{
    return lhs+rhs;
}

template<class T>
Operator<T>* PlusOperator<T>::clone()
{
    PlusOperator<T>* tempOp = new PlusOperator<T>;
    return tempOp;
}


#endif // __PLUSOPERATOR_H__