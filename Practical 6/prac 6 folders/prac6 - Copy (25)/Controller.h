//u21582735 Siyamthanda Ndlovu
//The Controller class

#include "Plane.h"
#include "Passenger.h"
#include "Cargo.h"

//See spec for inclusion strategy for templates
#ifndef CONTROLLER_H
#define CONTROLLER_H
template <class T>
class Controller {

private:
    Plane<T>* plane;//ugg this is so complex
    //a pointer to a plane object??? ^^
    //and its nots Plane* becuase we have to say Plane<T> because Plane is a template class??? ^^
public:
    Controller( Plane<T>* p );
    std::string loadOnPlane( T* t );
    double getTotalValue();
    std::string getPlaneContents();
};

#include "Controller.cpp"

#endif