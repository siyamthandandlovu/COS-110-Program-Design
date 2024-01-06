//u21582735 Siyamthanda Ndlovu
//The SecretCargo implementation file

#include "SecretCargo.h"
#include <iostream>
SecretCargo::SecretCargo( double w ) {
weight = w;
//std::cout << "SecretCargo::SecretCargo() is THIS : Weight = " << weight << "\n";
}

double SecretCargo::getWeight() const {
//std::cout << "SecretCargo::getWeight() returns : Weight = " << weight << "\n";
return weight;
}