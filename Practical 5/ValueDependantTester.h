//u21582735 Siyamthanda Ndlovu
#ifndef VALUEDEPENDANTTESTER_H
#define VALUEDEPENDANTTESTER_H

#include "NumberTester.h"

#include <cstddef>
class ValueDependantTester : public NumberTester {
private:
static int numAliveObjects; 

protected:
int value;

public:
ValueDependantTester(int val);
~ValueDependantTester();
//decided to comment this jsut in case it gives errors when submitting to fitchfork
//virtual bool evaluate(int val) =0;
//virtual NumberTester* clone() =0;
static int getNumAliveObjects();
};

#endif

//int ValueDependantTester::numAliveObjects = 0;