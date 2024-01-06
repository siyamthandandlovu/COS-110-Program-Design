#include "matrix.h"

#include <iostream>

using namespace std;

int main() {

    Matrix m = Matrix(0, 0);
    cout << "created first m" << endl;
    m.displayMatrix();
    //m.~Matrix();
    cout << endl;

    Matrix m2 = Matrix(6, 6); //immediately got a seg fault LMAO
    m2.displayMatrix();
    //m2.~Matrix();
    cout << "ok matrix number two has been set, (buncha zeroes) and destroyed " << endl;

    Matrix m3 = Matrix(3, 3);
    m3.setMatrix();
    m3.displayMatrix();

    cout << endl;

    m3.resizeRows(-1);
    cout << "gonna try resizing the rows to 10" << endl;
    m3.resizeRows(10); //m.resizeRows(10);//omg just realised i destroyed m earlier on but i was still trying to resize it
    cout << "this is after resizing M3 - you caught that though ngyabonga " << endl;
    m3.displayMatrix();

    m3.resizeRows(2);
    m3.displayMatrix();
    //cout << "Wrong m3 resizing" << endl;
    m3.resizeColumns(-1);
    m3.resizeColumns(1);
    m3.displayMatrix();
    cout << "\n\n\n\n\n Abouut to change column size to 13" << endl;
    m3.resizeColumns(13);
    m3.displayMatrix();


//m3.~Matrix();
//umm i commented ALL of the matrix destructors and c++ didi it for me? 
// wait whattt
//because before i was having a seg fault
//because i had freed all of the data and then the memory and everything would be freed again and then nothing would happen
    return 0;

}

/* Expected Output
1 1 1
1 1 1
1 1 1

0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0

1
2
3
4
5
6
7
8
9
1 2 3
4 5 6
7 8 9

Error: cannot have less than 1 row
Error: cannot have less than 1 column

 */