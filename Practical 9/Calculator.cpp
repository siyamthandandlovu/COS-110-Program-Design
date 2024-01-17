#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__
#include <cstddef>

#include "Calculator.h"//neh?

template<class T>
Calculator<T>::Calculator()
{
    //valueStack = NULL;//where do we get the value and operator stack from????
    //operatorStack = NULL;//do we create the stack ourselves????

    valueStack = new Stack<T>();
    operatorStack = new Stack< Operator<T>* >();//Operator<T>* is the TYPE
}

/*    Stack<T>* valueStack;
    Stack<Operator<T>*>* operatorStack;
    */

template<class T>
Calculator<T>::~Calculator()
{

   // valueStack->~Stack();
    //operatorStack->~Stack();
delete valueStack;
delete operatorStack;
    
}

template<class T>
void Calculator<T>::addValue(T val)//as in adding the value to the stack right???
{
    // function should add the passed in parameter to the appropriate member variable
    valueStack->push(val);
}

template<class T>
void Calculator<T>::addOperator(Operator<T>* op)
{
    //Operator<T>* ptCopy = new Operator<T>( );
    Operator<T>* ptCopy = op->clone();
    //operatorStack->push(op);
    operatorStack->push(ptCopy);
}

template<class T>
T Calculator<T>::removeValue()
{
    //return valueStack->pop();
   // return *(valueStack->pop());
   return valueStack->pop()->getData();
}

template<class T>
Operator<T>* Calculator<T>::removeOperator()
{
    return operatorStack->pop()->getData();
}

template<class T>
int Calculator<T>::numValues()
{
    return valueStack->size();
}

template<class T>
int Calculator<T>::numOperators()
{
    return operatorStack->size();
}

template<class T>
T Calculator<T>::calculate()
{
    if (valueStack->size() < 2)
    {
        return 0;
    }
    
    T ptVal1;
    T ptVal2; 
    T ptVal3;

    Operator<T>* ptOperator;
    
    //while ( numOperators() > 0 && numValues() > 1)
    while (operatorStack->isEmpty() == false && (operatorStack->size() == valueStack->size()-1 )  )
    {
        //ptVal1 = valueStack->pop();//wait but if i use the removeValue thing right?
        //ptVal1 = ( valueStack->pop() )->getData();//is this how we are soupposed to call it???
        //ptVal2 = ( valueStack->pop() )->getData();
        ptVal1 = this->removeValue();
        ptVal2 = this->removeValue();
       // ptVal3 = (operatorStack->pop() )->operator()(ptVal1 , ptVal2);
        ptOperator = this->removeOperator();
        ptVal3 = ptOperator->operator()(ptVal1 , ptVal2);
        valueStack->push(ptVal3);
    }
    return valueStack->getTop()->getData();
}


#endif // __CALCULATOR_H__