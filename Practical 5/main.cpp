//u21582735 Siyamthanda Ndlovu
#include <iostream>
#include <string>
#include "NumberTester.h"
#include "ValueDependantTester.h"
#include "ValueIndependantTester.h"
#include "IsDivisible.h"
#include "IsEvenOdd.h"
#include "IsGreater.h"
#include "IsPrimeNumber.h"
#include "IsSmaller.h"
#include "TesterInterface.h"

//display Interface details
void DisplayTesterInterfaceDetails(TesterInterface& objInterface);

using namespace std;

//==========================================================================
int main () {

/**/
cout << "\n\nBegin Testing IsDivisble\n\n";

NumberTester* ptNumTester1;
NumberTester* ptNumTester2;

IsDivisible* ptDivisible1;


IsDivisible DivisableObject1(14); 

ptNumTester1 = &DivisableObject1;
ptDivisible1 = &DivisableObject1;
ptNumTester2 = DivisableObject1.clone();//well i thought this would mean the NumberTester ValueDependenceTester and IsDivisible constructors would have to execute


cout << "\nIsDivisible Evaluate Function\n";
if ( ptNumTester1->evaluate(28) )
{
   cout << "ptNumTester1->evaluate(28) == true\n";
} else cout <<"ptNumTester1->evaluate(28) == false\n";


cout << "Alive Objects - ptNumTester1 : " << ptNumTester1->getNumAliveObjects() << endl;//this will be the static variable neh
cout << "Alive Objects - ptDivisible1 : " << ptDivisible1->getNumAliveObjects() << endl;//this will be the static variable neh
//after calling the clone function, you create a second IsDivisible object and for that reason, num alive objects is 2

cout << "\nAbout to delete ptNumTester2\n";
delete ptNumTester2;//ok so this is a NumberTester pointer; is that why the NumberTester destructor executes but not the other two ? (NumberTester ValueDependenceTester)
//only the NumberTester constructor executes and that is because the other destructors have fallen away("slicing") 
cout << "Alive Objects - ptDivisible1 (Again) : " << ptDivisible1->getNumAliveObjects() << endl;//this will be the static variable neh


/**/

/**/
cout << "\n\nBegin Testing IsGreater\n\n";
NumberTester* ptNumTesterA;

IsGreater IsGreaterObject1(37);//created my stack isgreater object
ptNumTesterA = &IsGreaterObject1;
if (ptNumTesterA->evaluate(45882) == true)
{
   cout << "ptNumTesterA->evaluate(45882) == true :) \n";
} else cout << "ptNumTesterA->evaluate(45882) is NOT true \n";

/**/

/**/
cout << "\n\nBegin Testing IsSmaller\n\n";
IsSmaller* ptSmallerObject;
IsSmaller objIsSmaller1(16);
ptSmallerObject = &objIsSmaller1;

if (ptSmallerObject->evaluate(11) == true)
{
   cout << "evaluate for ptSmallerObject returned true and 11 is smaller than 16\n";
}
/**/

/**/
cout << "\n\nBegin Testing IsEvenOdd\n\n";
IsEvenOdd* ptEvenOddObject1;
IsEvenOdd objEvenOdd1;
//IsEvenOdd objEvenOdd1(); was giving me an error, i guess bc you only need brackets when the constructor takes in values wow i had no idea
ptEvenOddObject1 = &objEvenOdd1;
if (ptEvenOddObject1->evaluate(18) == true)
{
   cout << "The IsEvenOdd evaluate function said 18 is an even number\n";
}

/**/

/**/
cout << "\n\nBegin Testing IsPrimeNumber\n\n";
IsPrimeNumber* ptIsPrimeNumber1;
IsPrimeNumber objIsPrimeNumber1;//created the object 
ptIsPrimeNumber1 = &objIsPrimeNumber1;
int arrNums[10] = {10 , 0 , 13 , 27 , 4 , 5 , 1 , 2 , 98456 , 5};


for (int i = 0; i < 10; i++)
{
   cout << i+1 << " : " << ptIsPrimeNumber1->evaluate(arrNums[i]) << endl;
}
/**/







cout << "\n\n=========================================================\n";
cout << "\nBegin Testing Tester Interface\n";
cout << "\n=========================================================\n\n";


//Testing : TesterInterface(int maxNumTests)

cout << "\n\nTesting : TesterInterface(int maxNumTests)\n\n";
TesterInterface objTesterInterface1(7);
//cout << "getCurrNumTesters() : " << objTesterInterface1.getCurrNumTesters() << endl;
for (int i = 0; i < 7; i++) {
if ( objTesterInterface1[i] == NULL )
   cout << i << " is indeed NULL " << endl;
}


//Testing : TesterInterface(TesterInterface& other) , remove Tester , add Tester , operator[]
cout << "\n\nTesting : TesterInterface(TesterInterface& other) , remove Tester , add Tester , operator[]\n\n";

TesterInterface* ptInterfaceA = NULL;
TesterInterface objTesterInterB(ptInterfaceA);//created a null interface by inputting a interface pointer that points to null
cout << "Members of objTesterInterB : \n";
DisplayTesterInterfaceDetails(objTesterInterB);

//create tester interface, create numTester pointer to primeNumObject and add that tester to num interface
TesterInterface* ptInterfaceB = new TesterInterface(4);
NumberTester* ptNumTester3 = ptIsPrimeNumber1;//ptNumTester3 points to what ptIsPrimeNumber points to
cout <<"Index of added tester : " << ptInterfaceB->addTester(ptNumTester3) << "\n\n";

//add IsEvenOdd Object to the tester interface
NumberTester* ptNumTester4 = ptEvenOddObject1;//our pointer pooints to even odd object
cout <<"Index of added tester : " << ptInterfaceB->addTester(ptNumTester4) << "\n\n";

//display interface summary
cout <<"objTesterInterB Summary after adding two testers\n";
DisplayTesterInterfaceDetails(objTesterInterB);
//and then the main function would end and i guess that would reuslt in the getters giving me 0

//add isSmaller object
NumberTester* ptNumTester5 = ptSmallerObject;
cout <<"Index of added tester : " << ptInterfaceB->addTester(ptNumTester5) << "\n\n";

//add isDivible object to testers array
NumberTester* ptNumTester6 = ptDivisible1;
cout <<"Index of added tester : " << ptInterfaceB->addTester(ptNumTester6) << "\n\n";

//add the same isDivible object to testers array BUT its full so it should return -1 and do nothing
NumberTester* ptNumTester7 = ptDivisible1;
cout <<"Index of added tester : " << ptInterfaceB->addTester(ptNumTester7) << "\n\n";

//remove the tester at index 2
bool isRemoved = ptInterfaceB->removeTester(2);
if (isRemoved = true) {
   cout << "TRUE : we were able to remove the object at 2\n\n";
}

//displaying summary
cout <<"objTesterInterB Summary after removing a tester from index 2\n";
DisplayTesterInterfaceDetails(objTesterInterB);

//adding tester after removing one from index 2
NumberTester* ptNumTester8 = ptIsPrimeNumber1;
cout <<"Index of added tester : " << ptInterfaceB->addTester(ptNumTester8) << "\n\n";


//dynamic memory deallocation for Interface Testing
//delete ptInterfaceB; // error : free(): double free detected in tcache 2 Aborted
//^^ why though?? I thought since we created this in main we have to be the ones to deallocate it?



//Testing : TesterInterface(TesterInterface* other) , evaluate , failedTests , numberOfFailedTests , 
cout << "\n\nTesting : TesterInterface(TesterInterface* other) , evaluate , failedTests , numberOfFailedTests \n\n";

//create new dynamic interface by passing in the pointer to another interface
TesterInterface* ptInterfaceC = new TesterInterface(ptInterfaceB) ;

//ok now we will just work with ptInterfaceC

//Testing evaluate function
bool evaluateValue = ptInterfaceC->evaluate(20);
if (evaluateValue == true)
   cout << "evaluateValue == TRUE meaning all of the tests returned a true value and there were no fails\n";
else
   cout << "evaluateValue == FALSE meaning some of the tests returned a false value and there were some fails\n";
//cout <<"\n";

//Testing numberofFailedTests function
int inumFailedTestsofInterfaceC = ptInterfaceC->numberOfFailedTests(20);
cout <<"The number of failed Tests in InterfaceC is = " << inumFailedTestsofInterfaceC << endl;

//Testing Failed Tests function
int* ptArrayTestFails = ptInterfaceC->failedTests(20);
for (int i = 0; i < inumFailedTestsofInterfaceC; i++)
{
   cout << "ptArrayTestFails["<< i <<"] = " <<  ptArrayTestFails[i] << endl;;
}

//


















cout << "Main Function Is about to go out of scope\n\n\n";
}
//==========================================================================


void DisplayTesterInterfaceDetails(TesterInterface& objInterface) {
//cout << "Members of objTesterInterB : \n";
cout << "Max number of testers: " << objInterface.getMaxNumTesters() << endl;
cout << "Current Number of Testers : " << objInterface.getCurrNumTesters() << endl;

}