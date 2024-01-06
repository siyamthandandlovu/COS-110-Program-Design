//u21582735 Siyamthanda Ndlovu
#include "IsGreater.h"
#include <iostream>
using namespace std;

int IsGreater::numAliveObjects = 0;
///^^^^^^
IsGreater::IsGreater(int value) : ValueDependantTester(value)  {//so this will call the constructor of both the valdep and numtester, num taking no values but valdep does take in inputs
numAliveObjects++; 
this->value = value;
//std::cout << "IsGreater::IsGreater(int value) || IsGreater::numAliveObjects = "<<numAliveObjects <<"\n";
}


IsGreater::~IsGreater() {
numAliveObjects--;
//std::cout << "IsGreater::~IsGreater() || IsGreater numAliveObjects = " << numAliveObjects << "\n";
}

int IsGreater::getNumAliveObjects() {
return numAliveObjects;
}

bool IsGreater::evaluate(int val) {
//std::cout << "bool IsGreater::evaluate(int val)\n";
    if (val > value)//if the mod is o ie there is no remainder //not value % val == 0
    {
        //std::cout << "val > value and VALUE == TRUE\n";
        return true;
    }
    //std::cout << "val is not > value and VALUE == FALSE\n";
    return false;
}

NumberTester* IsGreater::clone() {
//This function should return a new IsGreater pointer initialized with the inherited variable member.
//NumberTester* ptNewObject;
IsGreater* ptNewObject;
ptNewObject = new IsGreater(this->value); //since this->value belongs to the IsGreater object and it was inherited

//std::cout << "NumberTester* IsGreater::clone()\n";
return ptNewObject;
}