#ifndef CONTROLLER_CPP
#define CONTROLLER_CPP

#include "Controller.h"
//#include <iostream>

//The Controller implementation file

template<class T>
Controller<T>::Controller(Plane<T>* p) {
	this->plane = p;
}


template<class T>
std::string Controller<T>::loadOnPlane(T* t) {
	
	try {
		//do I need to NULL check here??
		this->plane->add(t);
		return "Success";
	}
	catch (const AboveWeightEx& e) {
		std::string out = "Could not load item, above max weight by ";
		out += e.getDifference();
		return out;
	}
}


template<class T>
double Controller<T>::getTotalValue() {

	try {
		//do I need to NULL check here??
		double total = this->plane->calculateValue();
		return total;
	}
	catch (const UnauthorisedEx&) {
		return 0;
	}


	//I'm getting the Error: Error	C2039	'getValue': is not a member of 'SecretCargo'
	//And I have NO IDEA how to fix this other than to make a seperate Undervalued catch for class
	//that isn't Secret Cargo
	//There's definitely another way to do this, but I'm only going to go there if I have time later


	// the item with the smallest value should be removed from the plane.
		//This is only done once(the total value is not checked afterwards).
		//The value returned is the total value on the plane excluding the item removed.
		

	catch (const UndervaluedEx<T>& e) {
		//do I need to NULL check here??

		//THIS IS CAUSING FUCKING ISSUES AND I HAVN:T A SINGLE CLUE HOW TO FIX IT AND I JUST WANNA CRYYYYYYY
		//I guess I can leave it out for now and just lose that mark??

		return e.getSum();

		/*T* underVal = e.getUndervalued();
		double remVal = underVal->getValue();
		this->plane->remove(underVal);
		return e.getSum() - remVal;*/
	}


	//catch (UndervaluedEx <Passenger> e) {
	//	//do I need to NULL check here??
	//	//should rather be ->???
	//	Passenger* underVal = e.getUndervalued();
	//	double remVal = underVal->getValue();
	//	this->plane->remove(underVal);
	//	return e.getSum() - remVal;
	//}
	//catch (UndervaluedEx <Cargo> e) {
	//	//do I need to NULL check here??
	//	//should rather be ->???
	//	Cargo* underVal = e.getUndervalued();
	//	double remVal = underVal->getValue();
	//	this->plane->remove(underVal);
	//	return e.getSum() - remVal;
	//}


	catch (const EmptyEx&) {
		return 0;
	}

}


template<class T>
std::string Controller<T>::getPlaneContents() {
	
	try {
		//do I need to NULL check here??
		return this->plane->getDescription();
	}
	catch (const EmptyEx&) {
		return "Nothing to report";
	}
	catch (const UnauthorisedEx&) {
		return "Not permitted";
	}
}


#endif


//Plane<SecretCargo>::getDescription in main
//Plane<SecretCargo>::getDescription in plane

//AboveWeightEx::getDifference in Exceptions
//AboveWeightEx::getDifference in main
//AboveWeightEx::getDifference in Plane

//Plane<SecretCargo>::calculateValue in main
//Plane<SecretCargo>::calculateValue in Plane

//AboveWeightEx::AboveWeightEx in Exceptions
//AboveWeightEx::AboveWeightEx in main
//AboveWeightEx::AboveWeightEx in Plane