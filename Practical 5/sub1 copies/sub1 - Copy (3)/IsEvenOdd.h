//u21582735 Siyamthanda Ndlovu
#ifndef ISEVENODD_H
#define ISEVENODD_H

#include "ValueIndependantTester.h"
#include <cstddef>

class IsEvenOdd : public ValueIndependantTester {
private:
static int numAliveObjects; 

public:
IsEvenOdd();
~IsEvenOdd();
//decided to comment this jsut in case it gives errors when submitting to fitchfork
//virtual bool evaluate(int val) =0;
virtual bool evaluate(int val);
//virtual NumberTester* clone() =0;
virtual NumberTester* clone();
static int getNumAliveObjects();
};

#endif