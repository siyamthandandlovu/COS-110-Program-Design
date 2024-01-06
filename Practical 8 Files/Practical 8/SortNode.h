#ifndef SN_H
#define SN_H

#include <string>
#include <sstream>

//SortNode class implementation here
template <class T>
class SortNode {
protected:
    T value;
public:
    SortNode<T>* next;
    SortNode<T>* prev;

    SortNode( T );
    std::string print();
    T getValue();
};

#include "SortNode.cpp"

#endif

/*
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
*/