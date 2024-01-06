#ifndef TOH_H
#define TOH_H

#include <stack>

#include "Exception.h"
#include "Disk.h"

template <class T>
class TowersOfHanoi
{
protected:
    std::stack<Disk<T>*>* t1;
    std::stack<Disk<T>*>* t2;
    std::stack<Disk<T>*>* t3;
    
    int startTower;
    int goalTower;

    TowersOfHanoi();
    
public:

    TowersOfHanoi(int startTower , int goalTower);
    void moveDisk(int dep , int dest);
    void addDisk(T diskData , int tower);
    bool validateGame();
    std::stack<Disk<T>*>* getTower(int tower);
    ~TowersOfHanoi();
    virtual void solveGame() = 0;
};

#include "TowersOfHanoi.cpp"

#endif