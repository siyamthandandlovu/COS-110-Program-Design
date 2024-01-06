//u21582735 Siyamthanda Ndlovu
#include "IsDivisible.h"
#include <iostream>
using namespace std;

int IsDivisible::numAliveObjects = 0;
///^^^^^^
IsDivisible::IsDivisible(int value) : ValueDependantTester(value)  {//so this will call the constructor of both the valdep and numtester, num taking no values but valdep does take in inputs
numAliveObjects++; 
this->value = value;
////std::cout << "IsDivisible::IsDivisible(int value) with value :" << this->value << "\nIsDivisible::numAliveObjects = "<<numAliveObjects <<"\n";
//std::cout << "IsDivisible::IsDivisible(int value) || IsDivisible::numAliveObjects = "<<numAliveObjects <<"\n";
}


IsDivisible::~IsDivisible() {
numAliveObjects--;
//std::cout << "IsDivisible::~IsDivisible() || IsDivisible numAliveObjects = " << numAliveObjects << "\n";
}

int IsDivisible::getNumAliveObjects() {
////std::cout << "int IsDivisible::getNumAliveObjects() is called || IsDivisible numAliveObjects = " << numAliveObjects << "\n";
return numAliveObjects;
}

bool IsDivisible::evaluate(int val) {
//std::cout << "bool IsDivisible::evaluate(int val)\n";
    if (val % value == 0)//if the mod is o ie there is no remainder //not value % val == 0
    {
        //std::cout << "val % value == 0 and VALUE == TRUE\n";
        return true;
    }
    //std::cout << "val % value != 0 and VALUE == FALSE\n";
    return false;
}

NumberTester* IsDivisible::clone() {
//This function should return a new IsDivisible pointer initialized with the inherited variable member.
//NumberTester* ptNewObject;
IsDivisible* ptNewObject;
ptNewObject = new IsDivisible(this->value); //since this->value belongs to the IsDivisible object and it was inherited

//std::cout << "NumberTester* IsDivisible::clone()\n";
return ptNewObject;
}