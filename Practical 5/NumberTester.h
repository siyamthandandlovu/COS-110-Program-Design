//u21582735 Siyamthanda Ndlovu
#ifndef NUMBERTESTER_H
#define NUMBERTESTER_H

#include <cstddef>
class NumberTester {
private:
static int numAliveObjects;

public: 
NumberTester();
~NumberTester();

virtual bool evaluate(int val) = 0;
virtual NumberTester* clone() = 0;
static int getNumAliveObjects();
};

#endif