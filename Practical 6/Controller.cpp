#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

//u21582735 Siyamthanda Ndlovu
//The Controller implementation file
//#include "Controller.h"
using namespace std;
template<class T>
Controller<T>::Controller(Plane<T>* p)
{
/*
Instead of creating a plane itself, a controller is bound to a specific plane through the constructor
*/
    plane = p;//not a deep copy
}

template<class T>
string Controller<T>::loadOnPlane(T* t)
{
/*
Load an item onto the plane, and return "Success". If an item puts the plane over max weight, 
it is simply not loaded, and an error message is returned in the form "Could not load item,
above max weight by amount-by-which-over-max-weight" ?? is there a space after the comma?? ^
*/  
try
{
    plane->add(t);
    //and if it succeeds we have to return success
   // return "Success";
}
catch(const AboveWeightEx& e)   //(const std::exception& e) idk where this notation comes from bro
{
    stringstream ss;
    ss << "Could not load item, above max weight by " << e.getDifference() << endl;
    //return "Could not load item, above max weight by " << e.getDifference() << endl;
    return ss.str();//^^ the fuck is this???
}

return "Success";//will only execute if it dosnt have a valiue
}

template<class T>
double Controller<T>::getTotalValue()
{
/*
Get the total value aboard the plane. After some debate, the plane company decided that if 
the controller is not authorised, the value is simply reported as 0 (remember that an exception 
is thrown if the controller is not authorised. By catching it, you can determine if you are 
authorised to view that information). If an UndervaluedEx is thrown by the plane, then the 
item with the smallest value should be removed from the plane. This is only done once 
(the total value is not checked afterwards). The value returned is the total value on the plane
excluding the item removed. If the plane is empty, 0 is returned.
*/

double totalPlaneValue = 0;
try
{
    totalPlaneValue = plane->calculateValue();
}
catch(const UnauthorisedEx& e1)//const,not to be edited, Unauthorised object called e
{
    return 0;//UnauthorisedEx
}
catch(const EmptyEx& e2)
{           
    return 0;//EmptyEx
}
catch(const UndervaluedEx<T>& e3) {
//std::cout << "undervalued was thrown here\n"; 
    plane->remove( e3.getUndervalued() );
    return e3.getSum();
}
//can i add a catch(...) {return 0; } ??^^

return totalPlaneValue;//necessary since there should be something being returned right^^?
}

template<class T>
string Controller<T>::getPlaneContents()  
{
/*
This returns the entirety of the planes’ contents (using its getDescription method). 
If the plane is empty, then "Nothing to report" is returned. If the controller is not 
authorised to view the contents of the plane, "Not permitted" is returned.
*/
try
{
   //string desc = plane->getDescription() ;
   return plane->getDescription() ;
}
catch(const EmptyEx& e1)
{
    return "Nothing to report";
}
catch(const UnauthorisedEx& e2)
{
    return "Not permitted";
}


//return desc;
}

#endif // __CONTROLLER_H__