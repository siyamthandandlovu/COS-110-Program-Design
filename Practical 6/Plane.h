//u21582735 Siyamthanda Ndlovu
//The Plane class

#include <vector>
#include "Exceptions.h"
#include "SecretCargo.h"

//See spec on inclusion strategy for templates
#ifndef PLANE_H
#define PLANE_H
template <class T>
class Plane {
    private:
    std::vector<T*> cargo;//vector called cargo that will hold pointers of type t(eg of type passenger)
    double maxWeight;

    public:
    Plane( double max );
    ~Plane();

    void add( T* item );
    void remove( T* item );

    std::string getDescription();
    double calculateValue();

};

#include "Plane.cpp"
#endif