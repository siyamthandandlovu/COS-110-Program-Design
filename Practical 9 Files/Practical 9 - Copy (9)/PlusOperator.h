#ifndef PLUSOPERATOR_H
#define PLUSOPERATOR_H
#include "Operator.h"

template <class T>

class PlusOperator : public Operator<T>
{
public:
    T operator() (T lhs, T rhs);
    Operator<T>* clone();
};

#include "PlusOperator.cpp"

#endif