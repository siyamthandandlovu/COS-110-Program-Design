//Siyamthanda Ndlovu u21582735
#ifndef PRAC2CODE_MATRIX_H
#define PRAC2CODE_MATRIX_H


#include <iostream>

class Matrix {
private:
    int ***matrix;//this means this is a 2d array not of ints but of dynamic ints. i think
    int rows, columns;

public:
    Matrix(int in_rows, int in_columns);

    ~Matrix();

    void resizeRows(int num_rows);

    void resizeColumns(int num_cols);

    void setMatrix();

    void displayMatrix();

};


#endif //PRAC2CODE_MATRIX_H
