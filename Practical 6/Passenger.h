//u21582735 Siyamthanda Ndlovu
//The Passenger class

#include <sstream>
#include <string>

#ifndef PASSENGER_H 
#define PASSENGER_H 
class Passenger {
private:
std::string ID;
double weight;
double ticketPrice;

public:
Passenger(std::string id ,double w ,double t );
std::string describe() ;//what does it mean for a class to not have a destructor?
double getWeight() const;//const at the end to show that the const is for the function
double getValue() const;
};
#endif