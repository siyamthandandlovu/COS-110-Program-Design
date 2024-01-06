#ifndef __RECURSIVESOLUTION_H__
#define __RECURSIVESOLUTION_H__

#include "RecursiveSolution.h"


template<class T>
RecursiveSolution<T>::RecursiveSolution(int startTower , int goalTower)
{
    this->startTower = startTower;
    this->goalTower = goalTower;

this->t1 = new std::stack< Disk<T>* >;
this->t2 = new std::stack< Disk<T>* >;
this->t3 = new std::stack< Disk<T>* >;
}

template<class T>
void RecursiveSolution<T>::solveGame()
{
    
}

template<class T>
int RecursiveSolution<T>::count()
{
    int count = 0;


    return count;
}

template<class T>
bool RecursiveSolution<T>::contains(T label)
{
    bool bContains = false;


    return bContains;
}
#endif // __RECURSIVESOLUTION_H__