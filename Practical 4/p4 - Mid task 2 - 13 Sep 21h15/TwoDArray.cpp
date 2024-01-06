#include "TwoDArray.h"
#include <iostream>

//so this means that the only constructor we have is a copy constructor?
TwoDArray::TwoDArray(int** array, int* sizes, int baseSize) {
this->baseSize = baseSize;//baseSize is the number of rows of the var "array"
//baseSize is the size of the array called sizes
std::cout << "TwoDArray(int** array, int* sizes, int baseSize) & baseSize is "<<this->baseSize<<"\n";  
this->sizes = new int[baseSize];//sizes points to an array of dynamic integers
for (int i = 0; i < this->baseSize; i++)//mayber remove it if we do not need it
{
    std::cout <<i<< " of "<<this->baseSize << "\n";
    //for each iteration of i we create a new number of columns
    //we have to create the sizes array first right bc it does not exist yet?//this->sizes[i] = int (sizes[i]);// i have not idea how this ran without an error
    this->sizes[i] = sizes[i];
    this->array[i] = new int[ sizes[i] ];
    std::cout << "Array Element " <<i << " with new array of size " << sizes[i] <<" is being created now\n";
    for (int k = 0; k < this->sizes[i]; k++)//^^
    {
        this->array[i][k]  = array[i][k];
    }
    
    //this->sizes[i] = sizes[i];//umm like, this would only work if se
    std::cout  <<i+1<< " : size : "<<this->sizes[i] << "\n";
}


    // so the arrray "sizes" is an array that contains the sizes of the arrays that are in array
    //this->array = array;//umm are these deep copied or WHAT
    //this-
std::cout << "TwoDArray(int** array, int* sizes, int baseSize) called and execution complete\n";
std::cout << "Testing the getter functions \n";

int * TestGetterSinglePt = getSizes();
std::cout<< "TestGetterSinglePt[1] : " << TestGetterSinglePt[1] << "\n";

int TestGetterStackInt = getBaseSize();
std::cout<< "TestGetterStackInt : " << TestGetterStackInt << "\n";

int ** TestGetterDoublePt = getArray();
std::cout<< "TestGetterDoublePt[2][1] : " << TestGetterDoublePt[2][1] << "\n";
}
   
TwoDArray::~TwoDArray() {
std::cout << "~TwoDArray() called\n";
}

//==============================================================================
//OVERLOADING << OPERATOR - freind function
//==============================================================================
std::ostream& operator<<(std::ostream& os, TwoDArray& tda) {//this should work
//umm so lik, how do we knoe the sizes of data array tds??
int cols,rows = 3;//well rows will be the baseSize and then the cols change depending on sizes[i]
int k;
//std::cout << "created t"
for (int i = 0; i < tda.baseSize; i++)
{
    for ( k = 0; k < tda.sizes[i] - 1; k++)//^ tricky line//cannot say this->sizes since this points to the ostream object that calls the << operator
    {
        os << tda.array[i][k] << " ";
    }//has to declare k outside the loop so it does not go out of scope and we can still use its vlaue in displaying the last number 
    //os << tda.array[i][*(tda.sizes) -1] << std::endl;//^ tricky line // ithink it only works when all the arrays have the same number of columns
    os << tda.array[i][k] << std::endl;//this should work no matter how many columns you have
}
std::cout << "operator<<(std::ostream& os, TwoDArray& tda) called\n";
return os;
}
//==============================================================================
//OVERLOADING << OPERATOR - freind function
//==============================================================================

int** TwoDArray::getArray() {
//so umm a deep or shallow copy bro? imma assume its a deep copy

int** arrayCopy = new int*[baseSize];
std::cout << "Created the array arrayCopy \n";
for (int i = 0; i < baseSize; i++) {
    //*arrayCopy = new int[ sizes[i] ];//*arrayCopy is the first one though right so the code compiled but you wouljd have been working with the same thingie over and over again ie overwriting the same memeroy 
    arrayCopy[i] = new int[ sizes[i] ];
    std::cout <<i << " getting the array \n"; 
    for (int k = 0; k < sizes[i]; k++)//sizes[i] is the size of the array
    {
    std::cout << i << " x " << k << "\n";//this is fine meaning array[i][k] is causing the seg fault
    //std::cout << arrayCopy[i][k] << " & " << array[i][k] <<"\n";//this
    arrayCopy[i][k] = this->array[i][k];//so that we actually copy in the data
    std::cout << arrayCopy[i][k] << " & " << array[i][k] <<"\n";//this
    }
}

std::cout << "int** TwoDArray::getArray() called\n";
return arrayCopy;
}

int* TwoDArray::getSizes() {

int* arrayCopy = new int[baseSize];
for (int i = 0; i < baseSize; i++) {
    arrayCopy[i] = sizes[i];
}

std::cout << "int* TwoDArray::getSizes() called\n";
return arrayCopy;//arrayCopy is a copy of the (private) sizes array
}

int TwoDArray::getBaseSize() {
std::cout << "int TwoDArray::getBaseSize() called\n";   
return baseSize;
}

TwoDArray::operator int**() {


/*
//if your getters work then all you have to do is return getArray()
//the TwoDArray object becomes an int** 
std::cout << "operator int** conversion called \n";
int** arrayCopy = new int*[baseSize];
for (int i = 0; i < baseSize; i++)
{
    *arrayCopy = new int[sizes[i]];
    for (int k = 0; k < sizes[i]; k++) {
        arrayCopy[i][k] = array[i][k];//so that we actually copy in the data
    }
    
}
std::cout << "operator int**() called and completed execution\n";
return arrayCopy;

*/
std::cout << "operator int** conversion called \n";
return getArray();
}

TwoDArray::operator int* () {

int* arrayCopy = new int[baseSize];
for (int i = 0; i < baseSize; i++) {
    arrayCopy[i] = sizes[i];
}

std::cout << "operator int* () called\n";
return arrayCopy;
}

TwoDArray::operator int () {
    return baseSize;
}