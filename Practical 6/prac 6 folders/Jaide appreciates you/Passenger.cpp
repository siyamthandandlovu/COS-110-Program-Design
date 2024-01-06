#include "Passenger.h"
//The Passenger implementation file

Passenger::Passenger(std::string id, double w, double t)
{
	this->ID = id;
	this->weight = w;
	this->ticketPrice = t;
}

std::string Passenger::describe()
{
	std::string out = "";
	//should have "ID" at front????
	//out += "ID";???
	out += this->ID;
	out += " <";
	out += this->getValue();
	out += "> (";
	out += this->weight;
	out += ")";

	return out;
}

double Passenger::getWeight() const {
	return this->weight;
}

double Passenger::getValue() const {
	return this->ticketPrice;
}