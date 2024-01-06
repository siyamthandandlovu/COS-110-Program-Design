#include "SecretCargo.h"
//The SecretCargo implementation file

SecretCargo::SecretCargo(double w)
{
	this->weight = w;
}

double SecretCargo::getWeight() const {
	return this->weight;
}
