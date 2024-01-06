#include "Cargo.h"
//The Cargo implementation file

Cargo::Cargo(double w, double ppw) {
	//ppw = price per weight of cargo
	this->weight = w;
	this->value = w * ppw;
}

std::string Cargo::describe() {
	std::string out = "<";
	out += this->getValue();
	out += "> (";
	out += this->getWeight();
	out += ")";

	return out;
}

double Cargo::getWeight() const {
	return this->weight;
}

double Cargo::getValue() const {
	return this->value;
}
