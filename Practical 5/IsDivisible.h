//u21582735 Siyamthanda Ndlovu
#ifndef ISDIVISIBLE_H
#define ISDIVISIBLE_H

#include "ValueDependantTester.h"
#include <cstddef>

class IsDivisible : public ValueDependantTester {
private:
static int numAliveObjects; 

public:
IsDivisible(int value);
~IsDivisible();
//decided to comment this jsut in case it gives errors when submitting to fitchfork
//virtual bool evaluate(int val) =0;
virtual bool evaluate(int val);
//virtual NumberTester* clone() =0;
virtual NumberTester* clone();
static int getNumAliveObjects();
};

#endif