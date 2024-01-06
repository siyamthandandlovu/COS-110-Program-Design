//u21582735 Siyamthanda Ndlovu
#ifndef ISPRIMENUMBER_H
#define ISPRIMENUMBER_H

#include "ValueIndependantTester.h"
#include <cstddef>

class IsPrimeNumber : public ValueIndependantTester {
private:
static int numAliveObjects; 

public:
IsPrimeNumber();
~IsPrimeNumber();
//decided to comment this jsut in case it gives errors when submitting to fitchfork
//virtual bool evaluate(int val) =0;
virtual bool evaluate(int val);
//virtual NumberTester* clone() =0;
virtual NumberTester* clone();
static int getNumAliveObjects();
};

#endif