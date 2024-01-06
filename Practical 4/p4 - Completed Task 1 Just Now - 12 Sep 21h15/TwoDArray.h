//The base 2D array class
#ifndef TWODARRAY_H
#define TWODARRAY_H
//# directives....

//Do not add any more #includes
#include <iostream>
#include <string>

//Define class below
class TwoDArray {
private:
int** array;
int* sizes;
int baseSize;

protected:
int** getArray();
int* getSizes();
int getBaseSize();

public:

TwoDArray(int** array, int* sizes, int baseSize);
~TwoDArray();
friend std::ostream& operator<<(std::ostream& os, TwoDArray& tda);//is afreind bc its gonna access the private two d array
//ok making ostream const doesnt make sense but it would for tdarray
//virtual int* operator[](int) =0;
operator int**();
operator int*();//given me "return specified for operator int"
operator int();//this is wild
};//didnt forget :)
#endif