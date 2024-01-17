//u21582735 Siyamthanda Ndlovu
//The Cargo class

#include <string>
#include <sstream>

#ifndef CARGO_H 
#define CARGO_H 
class Cargo {
private:
double weight;
double value;

public:
Cargo( double w , double ppw );
std::string describe();
double getWeight() const;
double getValue() const;
};
#endif