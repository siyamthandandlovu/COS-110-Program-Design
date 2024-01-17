#ifndef __MINUSOPERATOR_H__
#define __MINUSOPERATOR_H__
#include "MinusOperator.h"

template<class T>
T MinusOperator<T>::operator()(T lhs, T rhs)
{
    return lhs - rhs;
}

template<class T>
Operator<T>* MinusOperator<T>::clone()
{

    MinusOperator<T>* tempOp = new MinusOperator<T>();//
    //MinusOperator<T>* tempOp = new MinusOperator<T>()
    return tempOp;
}

#endif // __MINUSOPERATOR_H__