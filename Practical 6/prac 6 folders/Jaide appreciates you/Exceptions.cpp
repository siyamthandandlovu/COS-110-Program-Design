#ifndef EXCEPTIONS_CPP
#define EXCEPTIONS_CPP

#include "Exceptions.h"
//Exception implementations

/////////////////
//AboveWeightEx//
/////////////////
AboveWeightEx::AboveWeightEx(double wd) {
	this->weightDiff = wd;
}

double AboveWeightEx::getDifference() const {
	return this->weightDiff;
}


/////////////////
//UndervaluedEx//
/////////////////
template<class E>
UndervaluedEx<E>::UndervaluedEx(E* uv, double s)
{
	this->underVal = uv;
	this->sum = s;
}

template<class E>
E* UndervaluedEx<E>::getUndervalued() const
{
	return this->underVal;
}

template<class E>
double UndervaluedEx<E>::getSum() const
{
	return this->sum;
}



//////////////
//NotFoundEx//
//////////////

template<class E>
NotFoundEx<E>::NotFoundEx(E* nf){
	this->missing = nf;
}

template <class E>
E* NotFoundEx<E>::getNotFound() const {
	return this->missing;
}

#endif