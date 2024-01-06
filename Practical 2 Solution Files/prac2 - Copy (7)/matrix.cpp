//Siyamthanda Ndlovu u21582735
#include <iostream>
#include "matrix.h"
using namespace std;

//Do not change the displayMatrix() function
void Matrix::displayMatrix() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {

            cout << *matrix[i][j];

            if (j != columns - 1) {
                cout << " ";
            }
        }

        cout << endl;
    }
}







Matrix::Matrix(int in_rows, int in_columns) {
rows = in_rows;
columns = in_columns;

if (rows< 1 || columns <1)//make 3 by 3 matrix
{

matrix = new int **[3];
for (int i = 0; i < 3; i++)
{
rows = 3;
columns = 3;
	matrix[i] = new int * [3];
	for (int k = 0; k < 3; k++)
	{
	matrix[i][k] = new int (1);
	}
	
}

}
else if ((rows > 1) && (columns > 1))
{
matrix = new int **[rows];
for (int i = 0; i < rows; i++)
{
	matrix[i] = new int * [columns];
	for (int k = 0; k < columns; k++)
	{
		matrix[i][k] = new int (0);
		//matrix[i][k] = new int;
		//*matrix[i][k] = 0;
	}
}
}
}//constructor







Matrix::~Matrix() {
cout << "Destructor of "<< rows << "x" << columns << " Matrix has been called "  << endl;
for (int i = 0; i < rows; i++)
{	
	for (int k = 0; k < columns; k++)
	{
	delete matrix[i][k];//each dynamic int
	}
	delete [] matrix[i];//leaving this out gives me a seg fault
}
delete [] matrix;
cout << "Destructor is done executing" << endl;
//oooooohhh ok it looks like the destructor is
}//destructor









void Matrix::resizeRows(int num_rows) {
	//so if rows < num_rows then deallocate the whole thing?
	//if you call the constructor you dont change the columns number so yeah
if (num_rows < 1) {
cout << "Error: cannot have less than 1 row\n";// bc they say add an endline character << endl;
}
else if (num_rows < rows) {
cout << "Deleting rows" << endl;
//so like keep the first couple elements in the first copule rows?
for (int r = num_rows; r < rows; r++)//this according to the logic of the shi file
	{
	for (int c = 0; c < columns; c++) {
		cout << *matrix[r][c] << " " ;
		delete matrix[r][c]; // this was delete * matrix[r][c] dereferencing matrix THREE times//delete matrix[r][c];// deallocate the memory at  
		}//columns
	cout << endl;
	}//rows
	//delete [] matrix;
rows = num_rows;
cout << " We are done deleting rows and the array has been resized" << endl;
}//if rows < num_rows

else if (num_rows > rows) {
cout << "adding rows " << endl;

int ***tempMatrix;//cout << "created the var called temp matrix" << endl;;
tempMatrix = new int** [rows];//create new array to be exactly the same as matrix

for (int i = 0; i < rows; i++) {
	tempMatrix[i] = new int* [columns];//created columns for every row
	for (int c = 0; c < columns; c++) {
	tempMatrix[i][c] = new int (0);
	*tempMatrix[i][c] = *matrix[i][c];//assign each element
	cout << *tempMatrix[i][c] << " and " << *matrix[i][c] << endl;
	}//columns
}
cout << "created temp matrix  - the whoooole thing - ALSO why isnt this coming out" << endl;

//completely deallocate the OG matrix
cout << "before deallocation matrix has THIS many rows : " << rows << endl;
for (int i = 0; i < rows; i++) {	
for (int k = 0; k < columns; k++) {
	delete matrix[i][k];//each dynamic int
}
delete [] matrix[i];//leaving this out gives me a seg fault
}
delete [] matrix;
cout << " completely deallocated matrix " << endl;
//now reallocate matrix with num_rows number of rows
//cout << " rn matrix has THIS many rows : " << rows << endl;

matrix = new int **[num_rows];//created rows but 10 instead of 3
cout << " just assigned matrix to a bunch of rows " << endl;
//for (int i = 0; i < rows; i++) {//you said rows (ie 3) instead of num_rows
for (int i = 0; i < num_rows; i++) {
	matrix[i] = new int *[columns];//created columns
	cout << "rows " << endl;
	for (int c = 0; c < columns; c++) {
	matrix[i][c] = new int (0);//so this bigger array has all its values =0;
	cout << " another " << endl;
	//check if tempmatrix[i][c] exists (i<rows , c<cols) then assign *matrix[i][c] = *tempMatrix[i][c]
	if ((i < rows) && (c < columns)) {//cannot make rows=num_rows bc we still prev number of rows otherwise its gonna go outta bounds
		*matrix[i][c] = *tempMatrix[i][c];
		cout << "  assignment " << *matrix[i][c] << endl;
		}
	}
	//this will be on the row you just created
}
//rows = num_rows;//when i used row it tried to delete shit that was out of bounds

//destroy the temp matrix
for (int i = 0; i < rows; i++) {//bc tempMatrix still has the old OG number of rows
for (int k = 0; k < columns; k++) {
	delete tempMatrix[i][k];//each dynamic int
}
delete [] tempMatrix[i];
cout << "deleted a row " << endl;
} //delete [] matrix; //LOOOOOOOK
delete [] tempMatrix;


//officially change the number of rows
rows = num_rows;
cout << "rows : " << rows << " cols : " << columns << endl;
cout << "Done changing the row size " << endl;
}
//end of the entire functions
}











void Matrix::resizeColumns(int num_cols) {
if ( num_cols < 1) {
	cout << "Error: cannot have less than 1 column\n";
}
else if (num_cols < columns) {
	cout << "Deleting Columns : " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int c = num_cols; i < columns; i++)
		{
			delete matrix[i][c];
		}//we dont delete the rows themselves	
	}
columns = num_cols;	
}
else if ( num_cols > columns) {
cout << "\n\n\nAdding Columns : " << endl;




//create tmeporary matrix to hold old values
int ***tempMatrix = new int** [rows];//create new array to be exactly the same as matrix
for (int i = 0; i < rows; i++) {
	tempMatrix[i] = new int* [columns];//created columns for every row
	for (int c = 0; c < columns; c++) {
	tempMatrix[i][c] = new int (0);
	*tempMatrix[i][c] = *matrix[i][c];//assign each element
	cout << *tempMatrix[i][c] << " and " << *matrix[i][c] << endl;
	}//columns
}
cout << "created temp matrix  - the whoooole thing "<< endl;

//completely deallocate the OG matrix
cout << "before deallocation matrix has THIS many rows : " << rows << endl;
for (int i = 0; i < rows; i++) {	
for (int k = 0; k < columns; k++) {
	delete matrix[i][k];//each dynamic int
}
delete [] matrix[i];//leaving this out gives me a seg fault
}
delete [] matrix;
cout << " completely deallocated matrix " << endl;
//now reallocate matrix with num_cols number of columns

matrix = new int **[rows];//created rows but 10 instead of 3
cout << " just assigned matrix to a bunch of rows " << endl;
//for (int i = 0; i < rows; i++) {//you said rows (ie 3) instead of num_rows
for (int i = 0; i < rows; i++) {
	matrix[i] = new int *[num_cols];//created columns
	cout << "rows " << endl;
	for (int c = 0; c < num_cols; c++) {
	matrix[i][c] = new int (0);//so this bigger array has all its values =0;
	cout << " another " << endl;
	//check if tempmatrix[i][c] exists (i<rows , c<cols) then assign *matrix[i][c] = *tempMatrix[i][c]
	if ((i < rows) && (c < columns)) {//cannot make rows=num_rows bc we still prev number of rows otherwise its gonna go outta bounds
		*matrix[i][c] = *tempMatrix[i][c];
		cout << "  assignment " << *matrix[i][c] << endl;
		}
	}
	//this will be on the row you just created
}
//rows = num_rows;//when i used row it tried to delete shit that was out of bounds

//destroy the temp matrix
for (int i = 0; i < rows; i++) {//bc tempMatrix still has the old OG number of columns
for (int k = 0; k < columns; k++) {
	delete tempMatrix[i][k];//each dynamic int
}
delete [] tempMatrix[i];
cout << "deleted a row " << endl;
} //delete [] matrix; //LOOOOOOOK
delete [] tempMatrix;


//officially change the number of columns
columns = num_cols;	
cout << "rows : " << rows << " cols : " << columns << endl;
cout << "Done changing the column size " << endl;












}

}









void Matrix::setMatrix(){/*cout << "about to set matrix" << endl;int x;*/
for (int i = 0; i < rows; i++) {
	for (int c = 0; c < columns; c++) {/*cin >> x; cout << " x : " << x << " " ; *matrix[i][c] = x;*/
	cin >> *matrix[i][c];
	}	
	}
}