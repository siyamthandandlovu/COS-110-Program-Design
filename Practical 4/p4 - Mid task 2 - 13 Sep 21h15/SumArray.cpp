#include "SumArray.h"

SumArray::SumArray(int** array, int* sizes, int baseSize) : TwoDArray(array , sizes , baseSize) {
}

SumArray::~SumArray() {

}

int* SumArray::operator[] (int index) {
int numTotal = 0;
int numElements = getSizes()[index];
//getSizes()[index] is the SIZE of the array we are going to sum
//array[index] is the array whose elements we will be adding up and we access it as getArray()[]
for (int i = 0; i < getSizes()[index]; i++) {
    numTotal += getArray()[index][i];//twice dereferenced
}
int* ptTotal = new int (numTotal);

return ptTotal;//it shouldnt be a deep copy right??
}