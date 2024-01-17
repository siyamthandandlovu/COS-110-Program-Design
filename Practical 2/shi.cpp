#include <iostream>
using namespace std;

void display2DArray(int arrayD[][8] , int rows , int cols) {
for (int i = 0; i < rows; i++) {
    for (int k = 0; k < cols; k++) {
        cout << arrayD[i][k] << " ";
    }
    cout << endl;
}
}



int main () {
int mat [7][8];

for (int i = 0; i < 7; i++)
{
    for (int k = 0; k < 8; k++)
    {
        mat[i][k] = 10+i+k-k*i;
    }   
}

display2DArray(mat , 7 , 8);

cout << "Reduce table to how many rows? : ";//reduce
int rowChange;//reduce number of rows and change the elements of the ones that are delted to zero
cin >> rowChange;//say 4 

for (int i = rowChange; i < 7; i++)//from index 3
{
    for (int k = 0; k < 8; k++)//columns stay the same
    {
        mat[i][k] = 0;
    }
}
cout << "Change Matrix " << endl;
display2DArray(mat , 7 , 8);

int *** matrix;
int rows = 0, columns = 0;
if ((rows < 1) || (columns < 1)) {//intialise 3*3 full of ones
	cout << "The rows or columns are less than 1 so we are creating a 3x3 matrix" << endl;
	matrix = new int ** [3];//dynamic array of pointers (each pointing to an array of dynamic int objects)
		for (int r = 0 ; r < 3; r++) {
			matrix[r] = new int* [3]; //3 element array of int pointers that is dynamic
			cout << "Col " << r << " " << endl;			
            for (int c = 0; c<3 ; c++) {
				//*matrix[r][c] = 1;//* as in the value should be equalled to 1
				matrix[r][c] = new int (1);//making location matrix[r][c] point to a new integer object with the value 1
                cout << *matrix[r][c] << " ";
			}
            cout << endl;
		}
}//if either the rows or columns inputted is less than 1


//display matrix function
cout << "now their shit" << endl;
for (int i = 0; i < 3; i++) {
        for (int j = 0; j < columns; j++) {
            cout << *matrix[i][j];

            if (j != columns - 1) {
                cout << " - ";
            }
        }

        cout << endl;
    }

int array[3][3];
for (int i = 0; i < 3; i++)
{
    for (int k = 0; k < 3; k++)
    {
        cin >> array[i][k];
        cout << array[i][k];

    }
    cout << endl;

}



    return 0;
}