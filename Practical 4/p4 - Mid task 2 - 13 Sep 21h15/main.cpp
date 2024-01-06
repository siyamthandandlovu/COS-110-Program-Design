//This main gives some basic output for the prac
//If your output matches, you should be on the right track, but you may want to add some of your own tests as well.
//The output was captured on a machine running Ubuntu. The output should also hold true for VMs and WSL (provided they are Debian-based).
#include <iostream>
#include <cstdlib>
#include "TwoDArray.h"
//#include "Task1.cpp"
#include "Task2.cpp"


using namespace std;

int main()
{
	cout << "About to implement Phase 1 Run Test:\n";
	//Phase1::runTest();//ermmm namespace phase 1?
	//          ????????????????????????????
	//Phase 1 requires TwoDArray to be implemented as an object neh but since we have a PURE virtual function we cant do that
	//cout << "Ok Phase 1 Complete\n\n";
	cout << "======================================================================================================================\n";
	cout << "		BEGINNING OF PHASE 2 TESTING ";
	cout << "======================================================================================================================\n";

	//I am just sacred that this thing of it not running means that something is wrong that will fuck me over later on
	Phase2::runTest();
	return 0;
}


/*
For Task1:
Contents:
0 1 2
3 4 5
6 7 8

Contents of copied array:
0 1 2 
3 4 5 
6 7 8 
*/

/*
For Task2:
Count: 3
Sum: 3
Sorted: 
0 1 2 

Count: 3
Sum: 12
Sorted: 
3 4 5 

Count: 3
Sum: 21
Sorted: 
6 7 8 

*/