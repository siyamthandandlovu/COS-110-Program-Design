#ifndef __TOWERSOFHANOI_H__
#define __TOWERSOFHANOI_H__

#include "TowersOfHanoi.h"


template<class T>
TowersOfHanoi<T>::TowersOfHanoi()
{
    
}

template<class T>
TowersOfHanoi<T>::TowersOfHanoi(int startTower , int goalTower)
{
this->startTower = startTower;
this->goalTower = goalTower;

t1 = new std::stack< Disk<T>* >;
t2 = new std::stack< Disk<T>* >;
t3 = new std::stack< Disk<T>* >;
std::cout << "Towers of Hanoi COntructor || we set t1 t2 & t3 to new stacks\n";

/*
  
The functions associated with stack are: 
empty() – Returns whether the stack is empty – Time Complexity : O(1) 
size() – Returns the size of the stack – Time Complexity : O(1) 
top() – Returns a reference to the top most element of the stack – Time Complexity : O(1) 
push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1) 
pop() – Deletes the top most element of the stack – Time Complexity : O(1) 

*/

}

template<class T>
void TowersOfHanoi<T>::moveDisk(int dep , int dest)
{
if ( dep > 3 || dest < 1 || dep > 3 || dest < 1 || (dep == dest) )
    {
        throw Exception<T>::incorrectDiskMove(startTower , goalTower);
    } 
    //if startTower == goalTower 
    Disk<T>* ptTempDisk;
    switch (dep)
    {
    case 1: {
        if (t1 == NULL) 
            throw Exception<T>::emptyStack(dep);
        
        ptTempDisk = t1->top();
        t1->pop();
    }
    case 2: {
        if (t2 == NULL)
            throw Exception<T>::emptyStack(dep);//using emptyStack<T>(dep) gave me a problem
        
        ptTempDisk = t2->top();
        t2->pop();
    }        
    case 3: {
        if (t3 == NULL)
            throw Exception<T>::emptyStack(dep);

        ptTempDisk = t3->top();
        t3->pop();
    }    

    }

    switch (dest)
    {
    case 1: {
        t1->push(ptTempDisk);
        throw Exception<T>::movePlan(ptTempDisk , dep , dest);
    }
    case 2: {
        t2->push(ptTempDisk);
        throw Exception<T>::movePlan(ptTempDisk , dep , dest);
    }        
    case 3: {
        t3->push(ptTempDisk);
        throw Exception<T>::movePlan(ptTempDisk , dep , dest);
    }    
    }


}

template<class T>
void TowersOfHanoi<T>::addDisk(T diskData , int tower)
{
    if (tower < 1 || tower > 3)
    {
        std::cout << "addDisk || the tower you wanna add to isnt between 1 and 3\n";
        throw Exception<T>::invalidDiskAdd(tower , diskData);
    }

    switch (tower)
    {
    case 1: {
        std::cout << "addDisk || Adding Disk to Tower 1 \n";
       /* if (t1 == NULL) {
            throw Exception<T>::invalidDiskAdd(tower , diskData); }*/
        //if ( diskData.getLabel() > t1->top()->getLabel()) {
        if (t1 == NULL)
        {
            std::cout << "addDisk || Trying to add to tower 1 but t1 points to null \n";
            return;
        }

        
        if ( t1->empty() == true || t1->top() == NULL )//ie nothing has been added to the stack yet
        {
            std::cout << "addDisk || Adding disk to tower that is currently empty \n";
        }
        else if (t1->empty() == false && diskData > t1->top()->getLabel()) {
            //i think getLabel() gives an error since its for POINTERS neh???
            std::cout << "addDisk || Adding another disk to tower : diskData > t1->top()->getLabel() \n";
            throw Exception<T>::invalidTower(tower); }
        
        //t1->push(&diskData);//wait  WHY did i use the &
        //t1->push(&diskData);
        //think it should be t1->push( new Disk<T> (diskData));
        //std::cout << "addDisk || About to push a new disk onto stack t1 \n";
        t1->push(new Disk<T>(diskData));
        std::cout << "Added to Tower 1 with size now == " << t1->size() << "\n";
        //t1 = new std::stack< Disk<T>* >;
    }
    break;
    case 2: {
        /*if (t2 == NULL)
            throw Exception<T>::invalidDiskAdd(tower , diskData);*/

        if ( diskData > t2->top()->getLabel()) {
            std::cout << "addDisk || diskData > t1->top()->getLabel() \n";
            throw Exception<T>::invalidTower(tower); }        
       // t2->push(&diskData);
       t2->push(new Disk<T>(diskData));
    }  
    break;
    case 3: {
        /*if (t3 == NULL)
            throw Exception<T>::invalidDiskAdd(tower , diskData);*/
        if ( diskData > t3->top()->getLabel()) {
            std::cout << "addDisk || diskData > t1->top()->getLabel() \n";
            throw Exception<T>::invalidTower(tower); }

       // t3->push(&diskData);
       t3->push(new Disk<T>(diskData));
    }  

    }
//std::cout << "This is the end of the addDisk function so we were inserting in towe 3?\n";
}

template<class T>
bool TowersOfHanoi<T>::validateGame()
{
bool bValid = true;
int cValid = 0;
//checking if only one tower has disks

    if (t1==NULL || t1->empty() == false) {
        cValid++;//if its empty then we increase cValid's value
    }

    if (t2==NULL || t3->empty() == false) {
        cValid++;
    }

    if (t3 ==NULL || t3->empty() == false) {
        cValid++;
    }

    if (cValid != 1 )//|| cValid == 3 ie 3 disks point to null
    {
        std::cout << "TowersOfHanoi<T>::validateGame() || Try Again : Only one tower should be empty\n";
        bValid=false;
    }

if (goalTower < 1 || goalTower > 3 || startTower < 1 || startTower > 3 || goalTower == startTower )
{
    bValid = false;
}//but this wouldnmt have been set right? if the goal towers were invalid

if (goalTower == 1 && t1 != NULL)//if goal tower is 1 BUT t1 is the goal tower (suppososed to be empty) is NOT empty
{
    bValid = false;
}

if (goalTower == 2 && t2 != NULL)
{
    bValid = false;
}

if (goalTower == 3 && t3 != NULL)
{
    bValid = false;
}

//checking the start towers
if (startTower == 1 && t1 == NULL)
{
    bValid = false;
}

if (startTower == 2 && t2 == NULL)
{
    bValid = false;
}

if (startTower == 3 && t3 == NULL)
{
    bValid = false;
}



    
    
    return bValid;
    
}

template<class T>
TowersOfHanoi<T>::~TowersOfHanoi()
{
    Disk<T>* tempDisk = NULL;

    while (t1->empty() == false)//while stack is not empty
    {
        tempDisk = t1->top();
        t1->pop();
        delete tempDisk;
        tempDisk = NULL;
    }
    

    while (t2->empty() == false)//repeat until stack is empty
    {
        tempDisk = t2->top();
        t2->pop();
        delete tempDisk;  
        tempDisk = NULL;      
    }

    
    while (t3->empty() == false)//repeat until stack is empty
    {
        tempDisk = t3->top();
        t3->pop();
        delete tempDisk;  
        tempDisk = NULL;      
    }

}

template<class T>
std::stack<Disk<T>*>* TowersOfHanoi<T>::getTower(int tower)
{
switch (tower) 
{
case 1: {return t1;}
case 2: return t2;      
case 3: return t3;   
}

}

#endif // __TOWERSOFHANOI_H__