//u21582735 Siyamthanda Ndlovu
#include "IsEvenOdd.h"
#include <iostream>
using namespace std;

int IsEvenOdd::numAliveObjects = 0;

IsEvenOdd::IsEvenOdd() : ValueIndependantTester()  {//so this will call the constructor of both the valdep and numtester, num taking no values but valdep does take in inputs
numAliveObjects++; 
//std::cout << "IsEvenOdd::IsEvenOdd() || IsEvenOdd::numAliveObjects = "<<numAliveObjects <<"\n";
}

IsEvenOdd::~IsEvenOdd() {
numAliveObjects--;
//std::cout << "IsEvenOdd::~IsEvenOdd() || IsEvenOdd numAliveObjects = " << numAliveObjects << "\n";
}

int IsEvenOdd::getNumAliveObjects() {
return numAliveObjects;
}

bool IsEvenOdd::evaluate(int val) {
//std::cout << "bool IsEvenOdd::evaluate(int val)\n";
if (val == 0) return false;//immediately no, what about 2?

    if (val % 2 == 0)//if the mod is o ie there is no remainder //not value % val == 0
    {
        //std::cout << "val is even and VALUE == TRUE\n";
        return true;
    }
    //std::cout << "val is odd and VALUE == FALSE\n";
    return false;
}

NumberTester* IsEvenOdd::clone() {
IsEvenOdd* ptNewObject;
ptNewObject = new IsEvenOdd();
//std::cout << "NumberTester* IsEvenOdd::clone()\n";
return ptNewObject;
//the fact that the return type is Numtester* and we returned an IsEvenOdd object is polymorphism in itself since the IsEvenOdd object is being seen as a numtester as it is being returned by the function
}