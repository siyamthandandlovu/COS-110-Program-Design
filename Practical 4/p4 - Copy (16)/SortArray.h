//Siyamthanda Ndlovu u21582735
#ifndef SORTARRAY_H
#define SORTARRAY_H
#include "TwoDArray.h"
class SortArray : public TwoDArray {
public:
SortArray(int** array, int* sizes, int baseSize);// : TwoDArray(array,sizes,baseSize);
//~SortArray();//this gave me an abnormal exist status
virtual int* operator[](int);
};
#endif