//u21582735 Siyamthanda Ndlovu
#include "NumberTester.h"
#include <iostream>
using namespace std;

int NumberTester::numAliveObjects = 0;

NumberTester::NumberTester() {
numAliveObjects++;
std::cout << "NumberTester::NumberTester() || NumberTester::numAliveObjects = " << numAliveObjects << "\n";
}

NumberTester::~NumberTester() { 
numAliveObjects--;
std::cout << "NumberTester::~NumberTester()|| NumberTester::numAliveObjects = " << numAliveObjects <<  "\n";
}

int NumberTester::getNumAliveObjects() {
//std::cout << "int NumberTester::getNumAliveObjects()\n";
return numAliveObjects;
}