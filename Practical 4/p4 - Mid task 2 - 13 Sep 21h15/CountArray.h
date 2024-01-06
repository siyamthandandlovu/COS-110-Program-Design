#ifndef COUNTARRAY_h
#define COUNTARRAY_H
#include "TwoDArray.h"
class CountArray : public TwoDArray {
public:
CountArray(int** array, int* sizes, int baseSize);//i think this is passing the vars into the parent constructor so you are definingt the constructor instread of declaring it : TwoDArray(array,sizes,baseSize);
~CountArray();//we only had to DECLARE CountArray and ~CountArray because those are the functions we needed to add to out class since CountArray inherited the rest from TwoDArray
virtual int* operator[](int);//when i left this line out, the entire class CountArray was ABSTRACT and we couldn't create an instance of this class (CountArray)
};//end of class definition
#endif