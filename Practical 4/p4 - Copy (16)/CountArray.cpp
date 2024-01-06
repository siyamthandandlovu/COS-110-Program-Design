//Siyamthanda Ndlovu u21582735
#include "CountArray.h"
CountArray::CountArray(int** array, int* sizes, int baseSize) : TwoDArray(array,sizes,baseSize) {
//this array = array is already done by the TwoDArray Constructor right?
}

/*CountArray::~CountArray() {
//std::cout << "CountArray::~CountArray() executed\n";
}*/

//int* TwoDArray::operator[] (int index) //how THE FUCK did this compile??
int* CountArray::operator[] (int index) {//so it need to retun a pointer to a DYNAMIC integer for the counter array
//int x = *(getSizes(index));//umm, no mathcing function for the call? getSizes takes in what inpout type? NOne. it just returns sizes
int* ptCount = new int ( (getSizes()[index]) );//sizes is a PRIVATE array but getSizes gets a copy of the array sizes
//note getSizes() gives you sizes which is
return ptCount;//it shouldnt be a deep copy right??
}