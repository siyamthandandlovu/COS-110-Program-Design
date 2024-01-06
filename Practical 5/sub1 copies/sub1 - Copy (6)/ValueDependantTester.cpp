//u21582735 Siyamthanda Ndlovu
#include "ValueDependantTester.h"
#include <iostream>
using namespace std;

int ValueDependantTester::numAliveObjects = 0;

ValueDependantTester::ValueDependantTester(int val) {
value = val;
numAliveObjects++; 
//std::cout << "ValueDependantTester::ValueDependantTester(int val) || ValueDependantTester::numAliveObjects = "<<numAliveObjects << "\n";
}

ValueDependantTester::~ValueDependantTester() {
numAliveObjects--;
//std::cout << "ValueDependantTester::~ValueDependantTester() || ValueDependantTester::numAliveObjects = " << numAliveObjects << "\n";
}

int ValueDependantTester::getNumAliveObjects() {
//std::cout << "int ValueDependantTester::getNumAliveObjects()\n";
return numAliveObjects;
}