//u21582735 Siyamthanda Ndlovu
#include "ValueIndependantTester.h"
#include <iostream>
using namespace std;

int ValueIndependantTester::numAliveObjects = 0;

ValueIndependantTester::ValueIndependantTester() {
numAliveObjects++; 
std::cout << "ValueIndependantTester::ValueIndependantTester() || ValueDependantTester::numAliveObjects = "<<numAliveObjects << "\n";
}

ValueIndependantTester::~ValueIndependantTester() {
numAliveObjects--;
std::cout << "ValueIndependantTester::~ValueIndependantTester() || ValueDependantTester::numAliveObjects = "<<numAliveObjects << "\n";
}

int ValueIndependantTester::getNumAliveObjects() {
//std::cout << "int ValueIndependantTester::getNumAliveObjects()\n";
return numAliveObjects;
}