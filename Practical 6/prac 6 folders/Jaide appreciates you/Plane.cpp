#ifndef PLANE_CPP
#define PLANE_CPP

#include "Plane.h"
#include <algorithm>
//The Plane implementation file

template<class T>
Plane<T>::Plane(double max) {
	this->maxWeight = max;
}

template<class T>
Plane<T>::~Plane() {
	//TODO:: NOT HOW YOU DELETE VECTOR -- do later
	delete[] this->cargo;
}

template<class T>
void Plane<T>::add(T* item){

	double currentWeight = 0;
	for (int i = 0; i < this->cargo.size(); i++) {
		currentWeight += this->cargo[i]->getWeight();
	}

	if ((currentWeight + item->getWeight()) > this->maxWeight) {
		double weightOver = currentWeight + item->getWeight() - this->maxWeight;
		throw AboveWeightEx(weightOver);
	}
	else {
		this->cargo.push_back(item);
	}

}


template<class T>
void Plane<T>::remove(T* item) {

	if (this->cargo.size() == 0) {
		throw EmptyEx();
	}

	for (int i = 0; i < this->cargo.size(); i++) {
		if (this->cargo[i] == item) {
			this->cargo.erase(this->cargo.begin() + i);
			return;
		}
	}
		
	throw NotFoundEx<T>();

}


template<class T>
std::string Plane<T>::getDescription() {
	if (this->cargo.size() == 0) throw EmptyEx();

	std::string out = "";
	for (int i = 0; i < this->cargo.size(); i++) {

		out += this->cargo[i]->describe();
		if (i < this->cargo.size() - 1) out += "\n";

	}

	return out;
}


template <>
std::string Plane<SecretCargo>::getDescription() {
	if (this->cargo.size() == 0) throw EmptyEx();
	throw UnauthorisedEx();
}

template <class T>
double Plane<T>::calculateValue() {
	
	//no items: throw EmptyEx
	if (this->cargo.size() == 0) throw EmptyEx();

	//sort the cargo from smallest to biggest
	std::sort(this->cargo.begin(), this->cargo.end());

	//calculate total weight
	double total = 0;
	for (int i = 0; i < this->cargo.size(); i++) {
		total += this->cargo[i]->getValue();
	}

	if (this->cargo.size() >= 2) {
		if (this->cargo[0]->getValue() < (this->cargo[1]->getValue() / 2)) {
			throw UndervaluedEx<T>(this->cargo[0], total);
		}
	}

	return total;
}


template<>
double Plane<SecretCargo>::calculateValue() {
	if (this->cargo.size() == 0) throw EmptyEx();

	throw UnauthorisedEx();
}

#endif