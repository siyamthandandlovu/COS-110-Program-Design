//u21582735 Siyamthanda Ndlovu
//The Passenger implementation file
#include "Passenger.h"
#include <iostream>
Passenger::Passenger(std::string id ,double w ,double t ) {
ID = id;
weight = w;
ticketPrice = t;
//std::cout << "Passenger::Passenger() is THIS : " << ID << " " << weight << " " << ticketPrice << "\n";
}

std::string Passenger::describe() {
std::stringstream ss;
ss<< ID << " <" << ticketPrice << "> (" << weight << ")";//nothing at the end right?
std::string desc = "";
desc = ss.str();
//std::cout << "Passenger::describe() returns THIS : " << desc << "\n";

return desc;//^^ worried about what dec actually looks like
}

double Passenger::getWeight() const {
//std::cout << "Passenger::getWeight() returns THIS : " << weight << "\n";
    return weight;
}

double Passenger::getValue() const{
//std::cout << "Passenger::getValue() returns THIS : " << ticketPrice << "\n";
    return ticketPrice;
}