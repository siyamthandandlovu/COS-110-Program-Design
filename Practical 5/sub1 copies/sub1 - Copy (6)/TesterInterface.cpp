#include "TesterInterface.h"
#include <iostream>

//3 constructors, 1 destructor

TesterInterface::TesterInterface(int maxNumTests) {
maxNumTesters = maxNumTests;
currNumTesters = 0;//bc vele there is nothing at the start

if (maxNumTests < 1) {
testers = new NumberTester* [0]; //this would be a new array
}
else { // if max tests is more than 0
testers = new NumberTester* [maxNumTesters];//dynamic array of NumTester Pointers and then we go an make each of those pointers point to null
for (int i = 0; i < maxNumTesters; i++) {
    testers[i] = NULL;//this is fine since testers[i] is dereferenced once so its a pointer and we make it point to null
    //std::cout << i <<" NumTester* set to null\n";
}
}

//std::cout << "\nTesterInterface::TesterInterface(int maxNumTests) \n";
//std::cout << "maxNumTesters : " << maxNumTesters << " || currNumTesters : " << currNumTesters << "\n\n";
}

TesterInterface::TesterInterface(TesterInterface* other) {
/*
∗ This is a copy constructor for the TesterInterface class
∗ This function should make a deep copy of the passed in parameter
∗ If the passed in parameter is NULL initialize all the int variables with a value of 0 and the array with a size of 0.
∗ Hint: remember there is a difference between a null array and an array with a size of
*/
if (other == NULL) {
    maxNumTesters = 0;
    currNumTesters = 0;
    testers = new NumberTester* [0];
}
else {
    maxNumTesters = other->maxNumTesters;
    currNumTesters = other->currNumTesters;
    testers = new NumberTester* [maxNumTesters];//since this array doesnt exist for our object at first
    //testers is ** so testers is supposed to hold a bunch of dynamic POINTERS 
    //how would we create an array when the constructor has parameters 
    for (int i = 0; i < maxNumTesters; i++)//if i put maxnumtesters instead wouldnt i be copying nothing sometimes?
    {
        if (other->testers[i] != NULL) { //this makes sure that in the other object there is something to copy
        testers[i] = other->testers[i]->clone();//testers[i] here should point to a deep copy
        }
//we call the numbertesters construcor?????? but HOW bro i cant //testers[i] = testers how do we make these two equal?//^Q : will numALiveObjects == currNum testers then?
    }
    
}


//std::cout << "\nTesterInterface::TesterInterface(TesterInterface* other) \n";
//std::cout << "maxNumTesters : " << maxNumTesters << " || currNumTesters : " << currNumTesters << "\n\n";
}

TesterInterface::TesterInterface(TesterInterface& other) {
    maxNumTesters = other.maxNumTesters;
    currNumTesters = other.currNumTesters;
    //testers = new NumberTester[maxNumTesters];//since this array doesn't exist for our object at first
    testers = new NumberTester*[maxNumTesters];
    for (int i = 0; i < currNumTesters; i++)//if i put maxnumtesters instead wouldnt i be copying nothing sometimes?
    {
        //testers[i] = other.testers[i];//i think this is still a shallow copy
        if (other.testers[i] != NULL)
        {
        testers[i] = other.testers[i]->clone();//this should work since clone creates a dynamic object AND THEN testers[i] points to that object in memory
        }
        


        //testers[i] = testers how do we make these two equal?
        //^Q : will numALiveObjects == currNum testers then?
    }
   
//std::cout << "\nTesterInterface::TesterInterface(TesterInterface& other) \n";
//std::cout << "maxNumTesters : " << maxNumTesters << " || currNumTesters : " << currNumTesters << "\n\n";
}

TesterInterface::~TesterInterface() {
//like, delete testers? ^^ the loop since these dynamic pointers point to a presumabky dynamic object since the clones is how we add to the testers array
for (int i = 0; i < maxNumTesters; i++)//if i put maxnumtesters instead wouldnt i be copying nothing sometimes?
    {
        if (testers[i] != NULL)//if there it is NOT empty
        {
        delete testers[i];//deallocate the memory that testers[i] points to (ehich would be a clone of a IsEven odd or whatever. 
        } 
    }
        delete [] testers;//bc the array of pointer is dynamic and it what we have to deallocate
//std::cout << "\nTesterInterface::~TesterInterface() \n\n";
//^^and we dont have to delete the array returned by the failed tests function right?
}

int TesterInterface::addTester(NumberTester* tester) {
//std::cout << "\nint TesterInterface::addTester(NumberTester* tester)\n";
/*
∗ This function should add a deep copy of the passed in NumberTester object to the first index containing null of the testers array and increment the currNumTesters.
∗ The function should return the index that the new object was inserted into. 
∗ If the passed in parameter is null the function should return -1 and not alter the array. 
∗ If the array is full the function should return -1 and not alter the array.
∗ Hint: use the clone function to make a deep copy of the passed in parameter
*/
//peruse the testers array until

int index =0;
while ( (testers[index] != NULL) && (index < maxNumTesters) ) { // cannot say index<= maxNUmtesters because the biggest index possible is maxNUm-1
//  while  (testers[index] != NULL) //this cant be it bc it would be infinite if the array is full
index++;
//std::cout << "TesterInterface::addTester Loop || index == " << index << "\n";
}
//now check if index == maxNumTesters bc that means the array is full
if (index >= maxNumTesters || tester == NULL) {
    //std::cout << "Testers::AddTester function || the index == MaxNumTesters and testers array is full OR tester points to null so we return -1\n";
    //std::cout << "the index == " << index << "\n";
    return -1;
}

if (testers[index] == NULL) {
    //std::cout << "testers[index] == NULL so we add the passed in NumberTester to our testers array at index : " << index << "\n";
}

testers[index] = tester->clone();//testers[index] (which used to be null) should point to a new duplicate of the passed in NUmber tester variable

++currNumTesters;
getCurrNumTesters();
//std::cout << "This is the currNumTesters value : " << currNumTesters <<"\n";
return index;
}

bool TesterInterface::removeTester(int pos) {
////std::cout << "\nbool TesterInterface::removeTester(int pos)\n";
/*
∗ This function should remove the NumberTester* at the passed in parameter’s index in the array and decrement the currNumTesters variable.
∗ The NumberTester* object should be deleted and set to null. ∗ If the function was able to succesfully remove the NumberTester then the function should return true.
∗ If the passed in parameter’s index in the array is null then the function should return false.
∗ If the passed in parameter’s index is outside the bounds of the array the function should return false.
*/
if ( (testers[pos] == NULL) || (pos >= maxNumTesters) || (pos <0) )
{
    ////std::cout << "bool TesterInterface::removeTester || (testers[i] == NULL) || (i >= maxNumTesters) so VALUE == FALSE \n";
    //std::cout << "bool TesterInterface::removeTester ||  VALUE == FALSE \n";
    return false;
}

--currNumTesters;
//std::cout << "bool TesterInterface::removeTester || currNumTesters = " << currNumTesters <<  "\n";

delete testers[pos];//deallocate the memory NumberTester[] points to which works since NumberTester[] is a pointer to a dynamic object
testers[pos] = NULL;
//std::cout << "bool TesterInterface::removeTester || valid action to be taken so VALUE == TRUE \n";
return true;
}

bool TesterInterface::evaluate(int num) {
/*
∗ This function should iterate through all the NumberTesters currently in the testers array and pass the passed in parameter to the their evaluate function.
∗ If all the NumberTesters in the array return true then the function should return true else it should return false.
∗ If the array is empty the function should return false
*/

//std::cout << "\nbool TesterInterface::evaluate(int num)\n";
int iNumTrues = 0;
//determine number of trues

for (int i = 0; i < maxNumTesters; i++) {//if i put maxnumtesters instead wouldnt i be copying nothing sometimes?
//note that i changed currNumnTesters to maxNumTesters
if ( (testers[i] != NULL) && (testers[i]->evaluate(num) == true) ) {
    iNumTrues++;
}//(testers[i]!= NULL) && takes care of an assumption i made
}

//if not all NumberTesters in the array return true OR array is empty the function should return false
if ( (iNumTrues == currNumTesters) && (testers!=NULL) ) {
    //std::cout << "TesterInterface::evaluate || iNumTrues == currNumTesters so VALUE == TRUE\n";
    return true;
}
else {//if (testers!=NULL) doesnt check much since this will never happen
    //std::cout << "TesterInterface::evaluate || iNumTrues != currNumTesters OR array testers == NULLso VALUE == FALSE\n";
    return false;
} 

}

int* TesterInterface::failedTests(int num) {
/*
∗ This function should return an array containing all the indexes of tests that returned an evaluation result of false.
∗ The array should be sized exactly to the number of tests that failed. 
∗ If no tests failed or if the array does not contain any NumberTesters the functionshould return an array of size 0.
*/
//std::cout << "\nint* TesterInterface::failedTests(int num)\n";
//no tests failed or if the array does not contain any NumberTesters the functionshould return an array of size 0
if ( evaluate(num) == true || testers == NULL)//evaluate(num) == true means they're all true ANDDD testers == NULL means the array is empty right ^^
return new int[0];//^^oof can we do this? just return a new int[0]; A: 

//dynamic boolean array to hold evaluation results
int inumFails = 0;
bool* ptAllEvaluationResults = new bool[currNumTesters];

//find number of failed tests or should i use int TesterInterface::numberOfFailedTests(int num) ??
for (int i = 0; i < maxNumTesters; i++)//max bc we need to go through the whole array for the testers
{
    if (testers[i] != NULL)
    {
    ptAllEvaluationResults[i] = testers[i]->evaluate(num);//assigns boolean value
    if (ptAllEvaluationResults[i] == false) {
        inumFails++;//so we can create the array now
    }
    }
    
}
//creating the array we will return
int* ptArrayofIndexes = new int[inumFails];
int c = 0;
for (int i = 0; i < currNumTesters; i++)
{
    if (ptAllEvaluationResults[i] == false)
    {
        ptArrayofIndexes[c] = i;
        c++;//HA
    }
    
}
if (c+1 == inumFails)
{
    //std::cout << "TesterInterface::failedTests || c+1 is == inumFails : " << c << "\n";
}

delete [] ptAllEvaluationResults;//delete bool array
return ptArrayofIndexes;
}

int TesterInterface::numberOfFailedTests(int num) {
/*
∗ This function should return the number of NumberTester’s evaulations that failed. 
∗ If no tests failed or if the array is empty the function should return 0.
*/
//std::cout << "\nTesterInterface::numberOfFailedTests(int num)\n";
if ( evaluate(num) == true || testers == NULL)//if there are no fails (evaluate === true) or if testers is empty
return 0;

int inumFails = 0;
for (int i = 0; i < currNumTesters; i++) {
    if ( (testers[i] != NULL) && (testers[i]->evaluate(num) == false) ) {
        inumFails++;
    }
}

return inumFails;
}

NumberTester* TesterInterface::operator[] (int pos) {
/*
∗ This is the overloaded form of the operator[ ]. 
∗ This function should return the pointer at passed in index.
∗ If the index is outside of the bounds of the array the function should return null.
*/
//std::cout << "\nNumberTester* TesterInterface::operator[] (int pos)\n";
if (pos>= maxNumTesters)
{
    return NULL;
}
return testers[pos];
}

int TesterInterface::getCurrNumTesters() const{
/*
∗ This is a const function and should return the currNumTesters variable.
∗ In the appropriate h file decalre the function as: int getCurrNumTesters() const.
*/
////std::cout << "\nint TesterInterface::getCurrNumTesters() const || currNumTesters = " << currNumTesters << "\n";
return currNumTesters;
}

int TesterInterface::getMaxNumTesters() const{
/*
∗ This is a const function and should return the maxNumTesters variable
∗ In the appropriate h file decalre the function as: int getMaxNumTesters() const
*/
////std::cout << "\nint TesterInterface::getMaxNumTesters() const\n";
////std::cout << "getMaxNumTesters() : maxNumTesters is : " << maxNumTesters << "\n";
return maxNumTesters;
}

