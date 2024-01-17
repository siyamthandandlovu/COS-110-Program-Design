//u21582735 Siyamthanda Ndlovu
#ifndef TESTERINTERFACE_H
#define TESTERINTERFACE_H

#include <cstddef>
#include "NumberTester.h"

class TesterInterface {

private:
int maxNumTesters;
int currNumTesters;
NumberTester** testers;

public: 
//3 constructors, 1 destructor
TesterInterface(int maxNumTests);
TesterInterface(TesterInterface* other);
TesterInterface(TesterInterface& other);
~TesterInterface();

//other functions
int addTester(NumberTester* tester);
bool removeTester(int pos);
bool evaluate(int num);
int* failedTests(int num);
int numberOfFailedTests(int num);

NumberTester* operator[] (int pos);//returns a pointer to a Number Tester - from testers array
int getCurrNumTesters() const;
int getMaxNumTesters() const;

};

#endif