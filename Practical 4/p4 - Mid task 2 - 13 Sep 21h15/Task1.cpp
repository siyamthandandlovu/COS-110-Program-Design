//Include for Task1 testing

#ifndef T1T_CPP
#define T1T_CPP

#include "TwoDArray.h"
//#include <iostream>

using namespace std;


namespace Phase1 {//tf is a namespace manje?

	void runTest()
	{
	//cout << "Phase 1 : about to start the runTest" << endl;

	const int size = 3;

	int** array = new int*[size];
	int* sizes = new int[size];
	int count = 0;

	//Create array to be passed in as parameters
	for (int i=0;i<size;i++)
	{
		sizes[i] = size;
		array[i] = new int[size];

		for (int k=0;k<sizes[i];k++)
		{
			array[i][k] = count++;
		}
	}

/*
//==============================================================================
//ALTERNATIVE FOR ARRAY CREATION
//==============================================================================
//note lana that we have already said we will have 3 different arrays
sizes[0] = 4; sizes[1] = 2; sizes[2] = 5;

for (int i=0;i<size;i++) {//because array will hold the addresses to 3 dynamic arrays
	array[i] = new int[sizes[i]];

	for (int k=0; k<sizes[i]; k++) {
		array[i][k] = count++;//assigning it some random value
	}
}
//==============================================================================
//ALTERNATIVE FOR ARRAY CREATION
//==============================================================================
*/

	//cout << "Phase 1 : about to call the constructor" << endl;
	//Constructor call
	TwoDArray tester(array, sizes, size);

	//int** TestGetterDoublePt = tester.getArray();//did not work since the getter functions are private so we have to test then from within the class
	//int* TestGetterSinglePt = tester.getSizes();

	cout<<"Contents:\n"<< tester <<endl;
	//Test conversion overloads

int** othArray = tester;//oohhhhhh this is s

int* othSizes = tester;
int othSize = tester;

cout<<"Contents of copied array:"<<endl;
for (int i=0;i<othSize;i++)
{
	for (int k=0;k<othSizes[i];k++)
		cout<<othArray[i][k]<<" ";
	cout<<endl;
}
//cout <<"========================================================================\n";

for (int i=0;i<size;i++)
{
	delete [] array[i];
}
delete [] array;
delete [] sizes;
cout << "Seems like anything after the arrays being destroyed does not execute idk why thoug am I to assume its just some namespace thing?? ^^";
cout <<"========================================================================\n";

cout << "\n\n\nThe end of task One \n\n\n";//how come this line doesnt execute?? ^^
}//end of void runTest



}//end of namespace Phase 

#endif
