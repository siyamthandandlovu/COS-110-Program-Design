#include "SortArray.h"
SortArray::SortArray(int** array, int* sizes, int baseSize) : TwoDArray (array, sizes , baseSize) {

}
SortArray::~SortArray() {

}

int* SortArray::operator[] (int index) {
//int* ptNewSortedArray = new int (getSizes[index]);
int numElements = getSizes()[index];
int* ptNewSortedArray = new int[ numElements ];
for (int i = 0; i < numElements; i++) 
{
    *ptNewSortedArray = getArray()[index][i];//that should get the values
}
//now ptNewSortedArray points to a deep copy of the array that we need to sort

//sorting the array
int temp;
for (int i = 0; i < numElements-1; i++)
{
    for (int k = 0; k < numElements; k++)
    {
        
        if ( *ptNewSortedArray[i] > *ptNewSortedArray[k] )//if this first one is bigger than this second one
        {
            std::cout << "Switching elements : " << i << " & " << k << " \n";
            temp = *ptNewSortedArray[k];
            *ptNewSortedArray[k] = *ptNewSortedArray[i];
            *ptNewSortedArray[i] = temp;
            std::cout << "Switching Complete : " << i << " = " << *ptNewSortedArray[i] <<" & "<< k << " = " <<*ptNewSortedArray[k] <<" ^_^ \n";
        }
        
    }
    
}



//i will create a new array here and then reorganise THAT array

//
return ptNewSortedArray;
}