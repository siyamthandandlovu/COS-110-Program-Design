//u21582735 Siyamthanda Ndlovu
//The Cargo implementation file
#include "Cargo.h"
#include <iostream>//^^

Cargo::Cargo( double w , double ppw ) {
weight = w;
value = w * ppw; //^^
//std::cout << "Cargo::Cargo() is THIS : Weight = " << weight << " Value = " << value << "\n";
}

std::string Cargo::describe() {
std::string desc;
std::stringstream ss;

ss<< "Generic cargo " <<"<" << value << "> (" << weight << ")";//^^
desc = ss.str();
//std::cout << "Cargo::describe() returns THIS : " << desc << "\n";
return desc;
}

double Cargo::getWeight() const{
//std::cout << "Cargo::getWeight() returns THIS : " << weight << "\n";
    return weight;
}

double Cargo::getValue() const{
//std::cout << "Cargo::getValue() returns THIS : " << value << "\n";
    return value;
}