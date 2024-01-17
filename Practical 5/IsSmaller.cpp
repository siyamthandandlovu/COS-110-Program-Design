//u21582735 Siyamthanda Ndlovu
#include "IsSmaller.h"
#include <iostream>
using namespace std;

int IsSmaller::numAliveObjects = 0;
///^^^^^^
IsSmaller::IsSmaller(int value) : ValueDependantTester(value)  {//so this will call the constructor of both the valdep and numtester, num taking no values but valdep does take in inputs
numAliveObjects++; 
this->value = value;
std::cout << "IsSmaller::IsSmaller(int value) || IsSmaller::numAliveObjects = "<<numAliveObjects <<"\n";
}


IsSmaller::~IsSmaller() {
numAliveObjects--;
std::cout << "IsSmaller::~IsSmaller() || IsSmaller numAliveObjects = " << numAliveObjects << "\n";
}

int IsSmaller::getNumAliveObjects() {
return numAliveObjects;
}

bool IsSmaller::evaluate(int val) {
std::cout << "bool IsSmaller::evaluate(int val)\n";
    if (val < value)//if the mod is o ie there is no remainder //not value % val == 0
    {
        std::cout << "val < value and VALUE == TRUE\n";
        return true;
    }
    std::cout << "val is not < value and VALUE == FALSE\n";
    return false;
}

NumberTester* IsSmaller::clone() {
//This function should return a new IsSmaller pointer initialized with the inherited variable member.
//NumberTester* ptNewObject;
IsSmaller* ptNewObject;
ptNewObject = new IsSmaller(this->value); //since this->value belongs to the IsSmaller object and it was inherited

std::cout << "NumberTester* IsSmaller::clone()\n";
return ptNewObject;
}