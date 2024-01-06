//Siyamthanda Ndlovu u21582735
#include "chesspiece.h"
#include <iostream>
#include <string>

int Chesspiece::numberOfPieces = 0;

Chesspiece::Chesspiece() {
    name = "";
    numberOfPieces++;
    type = true;
    //std::cout<<"Chesspiece::Chesspiece() was called \n";
}

Chesspiece::Chesspiece(Chesspiece& obj) {
    //this->name = obj.getName();
    this->name = obj.name;
    //std::cout << "assigned name " << this->name << "\n";
    //this->name = obj.name;//possible bc we passed the object in by reference
    this->type = obj.type;
    numberOfPieces++;//this is a STATIC varibke for the entire chesspiece class
    //std::cout << "Chesspiece::Chesspiece(Chesspiece& obj) was called and we have this many chesspieces : " <<numberOfPieces <<"\n";
}


Chesspiece::Chesspiece(string in_name) {
    this->name = in_name;
    numberOfPieces++;
    //std::cout << "Chesspiece::Chesspiece(string in_name) was called \n";    
}


Chesspiece::~Chesspiece() {
    --numberOfPieces;
    //std::cout << "Chesspiece::~Chesspiece() was called \n";   
}

string Chesspiece::getName() const {
    return this->name;
}

int Chesspiece::getNumberOfPieces() const {
	return numberOfPieces;
}

//task 2

bool Chesspiece::getType() const {
return type;
}

Chesspiece::Chesspiece(string in_name, bool in_type) {
    name = in_name;
    type = in_type;
}