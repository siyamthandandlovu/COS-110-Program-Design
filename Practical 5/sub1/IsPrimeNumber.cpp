//u21582735 Siyamthanda Ndlovu
#include "IsPrimeNumber.h"
#include <iostream>
using namespace std;

int IsPrimeNumber::numAliveObjects = 0;

IsPrimeNumber::IsPrimeNumber() : ValueIndependantTester()  {
numAliveObjects++;  
//std::cout << "IsPrimeNumber::IsPrimeNumber() || IsPrimeNumber::numAliveObjects = "<<numAliveObjects <<"\n";
}

IsPrimeNumber::~IsPrimeNumber() {
numAliveObjects--;
//std::cout << "IsPrimeNumber::~IsPrimeNumber() || IsPrimeNumber numAliveObjects = " << numAliveObjects << "\n";
}

int IsPrimeNumber::getNumAliveObjects() {
return numAliveObjects;
}

bool IsPrimeNumber::evaluate(int val) {
//std::cout << "bool IsPrimeNumber::evaluate(int val)\n";

int inumFactors = 0;
for (int i = 1; i <= val; i++) {
    if (val % i == 0) { 
        inumFactors++;
    }//if its divisible by that number
}

if (inumFactors ==2) {
    //std::cout << " TRUE ";
    //std::cout << "inumFactors ==2";
    return true;
}
    //std::cout << " FALSE\n";
    return false;
}

NumberTester* IsPrimeNumber::clone() {
IsPrimeNumber* ptNewObject;
ptNewObject = new IsPrimeNumber();
//std::cout << "NumberTester* IsPrimeNumber::clone()\n";
return ptNewObject;
}