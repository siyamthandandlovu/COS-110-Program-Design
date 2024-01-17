//Siyamthanda Ndlovu u21582735
#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <iostream>
//class Chessboard;//foward class declaration
using namespace std;

class Chesspiece {

private:
    string name;
    bool type;
    static int numberOfPieces;

public:
    //friend class Chessboard;
    Chesspiece();
    Chesspiece(Chesspiece &obj);
    Chesspiece(string in_name);
    ~Chesspiece();
    string getName() const;
    bool getType() const;
    int getNumberOfPieces() const;//so the functions that are static do not have to be static themselves
    Chesspiece(string in_name, bool in_type);
    //Chessboard& operator=(const Chessboard &other);
};
   //Chesspiece::numberOfPieces = 0; does not work since the varible is still deemed private
   //int Chesspiece::numberOfPieces = 0;//`Chesspiece::numberOfPieces'; chesspiece.o:(.bss+0x0): first defined here
    //int Chesspiece::numberOfPieces = 0;
#endif //CHESSPIECE_H