#ifndef __ITERATIVESOLUTION_H__
#define __ITERATIVESOLUTION_H__

#include "IterativeSolution.h"



template<class T>
IterativeSolution<T>::IterativeSolution(int startTower , int goalTower)
{
    this->startTower = startTower;
    this->goalTower = goalTower;

this->t1 = new std::stack< Disk<T>* >;
this->t2 = new std::stack< Disk<T>* >;
this->t3 = new std::stack< Disk<T>* >;

}

template<class T>
void IterativeSolution<T>::solveGame()
{
    
}

template<class T>
void IterativeSolution<T>::moves(int numMoves)
{
    
}
#endif // __ITERATIVESOLUTION_H__