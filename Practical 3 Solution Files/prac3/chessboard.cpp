//Siyamthanda Ndlovu u21582735
#include "chesspiece.h"
#include "chessboard.h"
#include <iostream>
//int Chesspiece::numberOfPieces = 0;//thought it should work since

Chessboard::Chessboard(Chessboard &obj) {//obj exist and we create a new chessboard
this->rows = obj.rows;
this->columns = obj.columns;

board = new Chesspiece ** [rows];
////std::cout << "row " <<"\n";
//board = new **chesspiece [rows];//error : expected type tobe specified
    for (int i = 0; i < rows ; i++) {
    board[i] = new Chesspiece*[columns];//remember that board[i] is **
    //std::cout << " column " << i  <<"\n";
        for (int k = 0; k < columns ; k++) {//you didnt create a new dynamic var board[i][k] points to before you derefernce its value
            //*board[i][k] = *obj.board[i][k];
           // *board[i][k] =  Chesspiece (*obj.board[i][k]);
           board[i][k] = NULL;
           if (obj.board[i][k] != NULL)
           {
            //board[i][k] = new Chesspiece();//creeate an actual chesspiece we can assign the same values to
            //board[i][k]->name = obj.board[i][k]->getName();
            //board[i][k]->type = obj.board[i][k]->getType();
            //the above three lines created an error since CHessboard does NOT have access to chesspieces private memebrs without being a freind to the chesspiece class
            board[i][k] = new Chesspiece( obj.board[i][k]->getName() ,  obj.board[i][k]->getType()  );
            }
        }
    }
//std::cout << "Chessboard::Chessboard(Chessboard &obj) was called \n";
}

Chessboard::Chessboard(int in_rows, int in_columns) {
rows = in_rows;
columns = in_columns;

board = new Chesspiece** [rows];//NOTE that before i had board = new *chesspiece [rows]; until i realised two stars make sense since i have to have data of type chesspiece***
    for (int i = 0; i < rows ; i++) {
    board[i] = new Chesspiece*[columns];//this means each element on the board array is a POINTER to a DYNAMIC CHESSPIECE
        for (int k = 0; k < columns ; k++) {
            board[i][k] = NULL;
        }
    }
//std::cout<<"Chessboard::Chessboard(int in_rows, int in_columns) was called \n";
}

Chessboard::~Chessboard() {
    for (int i = 0; i < rows ; i++) {
        for (int k = 0; k < columns ; k++) {
           delete board[i][k];
        }
        delete [] board[i];
    }

delete [] board;
board = NULL;
//std::cout<<"Chessboard::Chessboard(int in_rows, int in_columns) was called \n";
}

void Chessboard::addChesspiece(Chesspiece *piece, int row, int column) {
board[row][column] = piece;//meaning board[row][column] POINTS TO piece
//std::cout << "void Chessboard::addChesspiece(Chesspiece *piece, int row, int column) was called \n";
}

void Chessboard::removeChesspiece(int row, int column) {
delete board[row][column];
board[row][column] = NULL;//i think
//std::cout << "void Chessboard::removeChesspiece(int row, int column) was called \n";
}

Chesspiece& Chessboard::at(int row, int column) const {//Chessboard::Chesspiece &at(int row, int column) const;//ok i think CHessboard::moves to before "at" since at is a member of the class//oh ok so the function name itself is AT and it return a cheespeice//so it should return board[row][column]
//return board[row][column];//I said I return a chesspiece (by reference) BUT here I am returning pointer to a chesspiece (by pointer or something)
//std::cout << "Chesspiece & Chessboard::at(int row, int column) const was called \n";
return *board[row][column];//yeah dereferencing it worked
}

//Task 2

Chessboard& Chessboard::operator=(const Chessboard& other) {//note the object already exists
//ooooooh you just have to destroy the first chessboard completely AND THEN create a new one
//this->~Chessboard;//i think this will lead to multiple deallocations
//so destroy the object WAIT is it a good idea to call the destructor her? because isnt the destructor automaticcaly called when the program ends or the object goes out of scope
//loop through entire board and if there are chesspieces, deallocate them FIRST AND set them to null
for (int i = 0; i < rows ; i++) {
    for (int k = 0; k < columns ; k++) 
    {
        if (board[i][k] != NULL)//if there is a chesspiece at board[i][k]
        {
            delete board[i][k];//deallocate the memory at board[i][k] 
            board[i][k] = NULL;
        }
    }
    } 
    //this->columns = other.columns;//this->rows = other.rows;
for (int i = 0; i < other.rows; i++) {
    for (int k = 0; k < other.columns; k++) {
        //for the board
        if (other.board[i][k] != NULL)//if there is an object to copy over
        {//then copy the pieces, member by member
        //this->board[i][k]->name = other.board[i][k]->getName();//‘//std::string Chesspiece::name’ is private within this context
        board[i][k] = new Chesspiece( other.board[i][k]->getName() ,  other.board[i][k]->getType()  );

            }  
        }  
    }
//std::cout << "Chessboard& Chessboard::operator=(const Chessboard &other) was called \n";
return *this;//return thr actual chessboard object
}

Chessboard& Chessboard::operator+=(const Chessboard &rhs) {//Chessboard::Chessboard isnt necessary because we just want to say that the function returns type
for (int i = 0; i < rhs.rows; i++) {
    for (int k = 0; k < rhs.columns; k++) {
        if ( (board[i][k] == NULL) && (rhs.board[i][k] != NULL) )//if a piece on the right exists
        {
           // board[i][k] = new Chesspiece();
           // board[i][k]->name = rhs.board[i][k]->getName();
           // board[i][k]->type = rhs.board[i][k]->getType();    
            board[i][k] = new Chesspiece( rhs.board[i][k]->getName() ,  rhs.board[i][k]->getType()  );

        } 
    }  
}
//std::cout << "Chessboard::Chessboard(Chessboard &obj) was called \n";
return *this;
}