#include <iostream>
#include <iomanip>
#include <string>
#include <fstream> 
#include <sstream>

using namespace std;

void readFile(istream &infile);
double stringToDoubleConversion(string line);
string getIndividualWord(string line);
void TestingDynamicMatrix();


int main() {

cout << "\n\nTesting Matrix Constructors\n\n";
//Matrix* ptMatrix1 = new Matrix(4,3);
double arrDoubles[4] = {98.54 , 548.5847613 , 64.354 , 546.69};
for (int i = 0; i < 3; i++) {
    cout << setw(10) << setprecision(5) << arrDoubles[i];
    }
cout << setw(10) << setprecision(5) << arrDoubles[3] << endl;

cout << "\nTesting Transpose Logic : \n" << endl;

//create a 2 by 4 2d array of matrices
int arrFirstArrInts[2][4] = {{96,14,94,51},{40,60,79,96}};
cout << "The frist array: \n";
for (int i = 0; i < 2; i++)
{
   for (int j = 0; j < 4; j++)
   {
    cout << i<<"x"<<j<<" : " <<arrFirstArrInts[i][j] << " ";
 //   arrSecondArrInts[i][j] = arrFirstArrInts[j][i];
//    cout << arrSecondArrInts[i][j] << " ";
   }
   cout << endl;
}

int arrSecondArrInts[4][2];

//displayingthe array values
cout << "The second array being compared to the first\n";
for (int i = 0; i < 4; i++)
{
   for (int j = 0; j < 2; j++)
   {
    cout << i<<"x"<<j<<" : " <<arrFirstArrInts[j][i] << " == ";
    arrSecondArrInts[i][j] = arrFirstArrInts[j][i];
    cout << arrSecondArrInts[i][j] << " ";
   }
   cout << endl;
}


cout << "\n\nTesting Matrix Multiplication Logic : \n" << endl;

//int arrThirdArrInts[4][3] = {{69,72,30},{83,61,44},{96,34,72},{14,22,70}};
int arrThirdArrInts[2][3] = {{69,72,30},{83,61,44}};
cout << "Columns in arrSecondArrInts (2) == rows in arrThirdArrInts (2) multiplying arrSecondArrInts x arrThirdArrInts is possible : \n";


cout <<"\nTesting the print file for 5 element array\n";



cout << "Lets display the array : \n";
for (int i = 0; i < 5; i++) {
   cout << i << " : " << arrDoubles[i] << endl;
}

cout <<"\nTesting the reversing of an array\n";
double arrReverseArray[5] = { 9.8959 , 9946.2 , 71.223 , 1737.3 , 796.46};
cout << "Lets display the array before it is reversed : \n";
for (int i = 0; i < 5; i++) {
   cout << i << " : " << arrReverseArray[i] << endl;
}
//reversing array
//creating a copy
double arrReverseArrayCopy[5];
for (int i = 5-1; i >= 0; i--) {
   arrReverseArrayCopy[i] = arrReverseArray[i] ;
}
for (int i = 0 , j = 5-1 ; i < 5 && j>-1 ; i++ , j--)
{
   cout << "i : " << i << " AND j : " << j << endl;
   arrReverseArrayCopy[j] = arrReverseArray[i];
}


cout << "Display of array after reversal : \n";
/*for (int i = 5-1; i >-1; i--)
{
  // cout << i << " : " << arrReverseArray[i] << endl;
}*/

for (int i = 0; i < 5; i++)
{
   cout << i << " : " << arrReverseArrayCopy[i]<< endl;
}


cout << "\n";
cout << "\n\n\nTesting the double** matrix\n\n";

TestingDynamicMatrix();
TestingDynamicMatrix();
TestingDynamicMatrix();













return 0;
}

void TestingDynamicMatrix() {
cout << "Input for rows and columns\n";
int r, c;
cin >> r >> c;




double** matrix = new double*[r];
std::cout << "matrix = new double*[rows];\n";
for (int i = 0; i < r; i++) {

    matrix[i] = new double[c];//fault when
    //std::cout << " matrix[i] = new double[cols];\n";
    for (int k = 0; k < c; k++) {
        std::cout << i ;
        matrix[i][k] = 0;
        std::cout << " x " << k << " == " << matrix[i][k] << "     ";
        
    }
    cout << "End of row : " << i << endl;
    
}
cout << endl << endl;
}


void readFile(istream &infile) {

double dDoublesArray[5];
std::string sLine;

//display all contents
while (getline(infile , sLine)) {
   std::cout << "Line : " << sLine << endl;
} 

std::string loopString;
std::cout << "We are going to try and place values in array\n";
 
for (int i = 0; i < 5-1; i++) {
   loopString = getIndividualWord(sLine);
   dDoublesArray[i] = stringToDoubleConversion(loopString);
   //erase the sline
   sLine.erase(0, sLine.find(" "));
	cout << "sLine value AFTER deletion : " << sLine << endl;
   
}

dDoublesArray[5-1] = stringToDoubleConversion(loopString);

getline(infile , sLine);//this gets the FIRST line
}


double stringToDoubleConversion(string line) {
	stringstream s1(line);
	double temp = 0;
	s1 >> temp;
   cout << "stringToDoubleConversion : " << temp << "\n";
	return temp;
}


string getIndividualWord(string line) {
   string newID;
   int ipos; //position of the space
   ipos = line.find(" ",0);

   newID.append(line , ipos +1 , line.length());
   cout << "getIndividualWord : " << newID << "\n";   
   return newID;
}

