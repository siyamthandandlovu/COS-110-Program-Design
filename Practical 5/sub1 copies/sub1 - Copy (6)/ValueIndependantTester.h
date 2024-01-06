//u21582735 Siyamthanda Ndlovu
#ifndef VALUEINDEPENDANTTESTER_H
#define VALUEINDEPENDANTTESTER_H

#include "NumberTester.h"

#include <cstddef>
class ValueIndependantTester : public NumberTester {
private:
static int numAliveObjects; 

public:
ValueIndependantTester();
~ValueIndependantTester();
//decided to comment this jsut in case it gives errors when submitting to fitchfork
//virtual bool evaluate(int val) =0;
//virtual NumberTester* clone() =0;
static int getNumAliveObjects();
};

#endif