#ifndef __MULTIPLYOPERATOR_H__
#define __MULTIPLYOPERATOR_H__

#include "MultiplyOperator.h"

template<class T>
T MultiplyOperator<T>::operator()(T lhs, T rhs)
{
    return lhs * rhs;
}

template<class T>
Operator<T>* MultiplyOperator<T>::clone()
{
    MultiplyOperator<T>* tempOp = new MultiplyOperator<T>();
    return tempOp;
}

#endif // __MULTIPLYOPERATOR_H__