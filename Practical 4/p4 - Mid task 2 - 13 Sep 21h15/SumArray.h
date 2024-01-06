#ifndef SUMARRAY_H
#define SUMARRAY_H
#include "TwoDArray.h"
class SumArray : public TwoDArray {
public:
SumArray(int** array, int* sizes, int baseSize);
~SumArray();
virtual int* operator[](int);          
};
#endif