//u21582735 Siyamthanda Ndlovu
#ifndef __PLANE_H__
#define __PLANE_H__

//The Plane implementation file

//#include "Plane.h"
/*
• Create a vector with template parameters, e.g vector<int> vec; 
• Add an item to the back of a vector using vec.push_back(item);
• Access an item like you would with an array, with [ ]
• To get the number of items in a vector, use the vec.size() method 
• To remove an item at an index i, use vec.erase(vec.begin() + i)
*/
using namespace std;

template<class T>
Plane<T>::Plane(double max)
{
/*
//A constructor which takes in the max weight that the plane can support. 
//The vector will automatically initialise to empty (as it should be, 
//since a plane starts of unloaded)*/
maxWeight = max;
//so cargo vector<T> is just done automatically?how?
//when the object is created, the members are created as well
}



template<class T>
Plane<T>::~Plane()
{
//Destructor, which deletes everything in the vector cargo
int inumitems = cargo.size();//int is fine since we have
for (int i = 0; i < inumitems; i++) {
    cargo.erase( cargo.begin() + i );
}
//everything should be erased
}


template<class T>
void Plane<T>::add(T* item)
{
/*
Adds an item of the template type to the back of the vector. 
If the plane would be put over its max weight, 
an AboveWeightEx is thrown instead and the item is not added.
*/
//find current weight

if (item == NULL) {
    cargo.push_back(item);
    return;
}



double currWeight = 0;
for (int i = 0; i < cargo.size(); i++) {
    if ( cargo[i] != NULL ) {
    currWeight += cargo[i]->getWeight();//fine since cargo[i] means we are working w the object which is a POINTER, one that has the getWeight functions
    }
}
//find what weight will be if we add the object that item points to
double potentialWeight = currWeight + item->getWeight();
if ( potentialWeight > maxWeight ) {
throw AboveWeightEx( item->getWeight() );
}//ok but we dont need the else angithi?
else {
cargo.push_back(item); //item neh since we push back pointers??^^
//cout << "WE are adding a new item at address : " << item << "\n";
}


}

template<class T>
void Plane<T>::remove(T* item)
{
/*
Removes and deletes the first instance of a specified item from the vector 
(erase calls delete itself). Note: we define two objects to be the same 
if they share the same memory address, not the same characteristics. 
If there are no items aboard, en EmptyEx should be thrown.
Similarly, if the item is not found, a NotFoundEx is thrown
*/   



if ( cargo.size() == 0 ) {
    throw EmptyEx();//ok i throw empy
}
else // we will traverse through the entire vector
{
    for ( int i = 0; i < cargo.size(); i++ ) {
        if ( (item == cargo[i]) /*&& (cargo[i]!= NULL) */) {//cargo[i] is a pointer, cargo is a vector of pointers
            cargo.erase(cargo.begin() + i);
            //remove the item and then return
            return;
        }
    }
}

//this means you have not returned & left the function, meaning the item was not found
throw NotFoundEx<T>(item);//item into it since it was item that was not found right?
}

//DOUBLE IMPLEMENTATION

template<class T>
string Plane<T>::getDescription()
{
/*
]Return a description of all items on the plane, as a string. 
The description of each item in the cargo vector is added to the 
description, in order, and separated by a newline (the last item is
not terminated by a newline). If there are no items, 
an EmptyEx instance should be thrown
*/
string desc = "";
if ( cargo.size() == 0 )//empty
{
    throw EmptyEx();
}
//otherwise go through the whole thing and append decriptions to desc
//int ival;
for (int i = 0; i < cargo.size() - 1; i++) {
    if (cargo[i] != NULL)//null check idk
    {
     desc = desc + cargo[i]->describe() + "\n";// << endl;   
    }
}

//desc += cargo[ival]->describe();
if (cargo[cargo.size() - 1] != NULL)//null check idk
    {
desc += cargo[cargo.size() - 1]->describe();//cargo.size() - 1 is the index of the last element neh?^^
    }
return desc;
}


template<class T>
double Plane<T>::calculateValue() {
/*
Calculate the total value of all the items on the plane. 
If there are no items on the plane, an instance of EmptyEx should be thrown. 
In addition, the plane company has decided on the following to save on fuel: 
if an item with the smallest value is found to have a value less than half the value of 
the next lest valuable item, it should be noted in the form of an exception. 
The UndervaluedEx exception should be thrown, with the least valuable item and the sum of all values 
(excluding the least valuable item) as parameters.
This way, when the exception is handled, the handler will know both the least valuable item 
and the sum of all values up until that point. If there are no items, an 
EmptyEx instance should be thrown.
*/   

//so get smallest value, get second smallest VALUE
/*
int indexSmallest
 and if smallest->getValue() < 0.5* secondsmallest->getValue() then do this:
The UndervaluedEx exception should be thrown, with the least valuable item and the sum of all values 
(excluding the least valuable item) as parameters.
pass in smallest pointer 
how do we get the sum??
sum = sum alladem and then (getting all of the valueSum += cargo[i]->getValue() )
sum = sum - smallest->getValue()
*/


if ( cargo.size() == 0 ) {
    throw EmptyEx();
}//i dont need to put this in an if else statment though

if ( cargo.size() == 1 ) {
    cargo[0]->getValue();
}//if the array is a size of 1 then you just get the 

double TotalValue = 0;
int indexSmallest, indexSecondSmallest;
//find smallest index
indexSmallest = 0;//let smallest item be the first
for (int i = 0; i < cargo.size(); i++) {//we can start at 1??
    if (  cargo[i]->getValue() < cargo[indexSmallest]->getValue() ) {
        indexSmallest = i;
    }
}

//find second smallest index
indexSecondSmallest = 0;
for (int i = 0; i < cargo.size(); i++) {//we can start at 1??
    if ( (cargo[i]->getValue() < cargo[indexSecondSmallest]->getValue()) && (i !=indexSmallest)  ) {
        indexSecondSmallest = i;
    }
}


//decide if we should throw the exception or not
if ( cargo[indexSmallest]->getValue() < 0.5* cargo[indexSecondSmallest]->getValue() )
{
//sum all the values and subtract cargo[indexSmallest]->getValue()
//then throw UndervaluedEx
//cargo[indexSmallest] is the passed in thingie

for (size_t i = 0; i < cargo.size(); i++) {
    TotalValue += cargo[i]->getValue();
}
TotalValue = TotalValue - cargo[indexSmallest]->getValue();
//now the value is ready to be passed into the excpetion we are throwing

throw UndervaluedEx<T>( cargo[indexSmallest] , TotalValue );


}
for (size_t i = 0; i < cargo.size(); i++) {
    TotalValue += cargo[i]->getValue();
}
return TotalValue;

}


//is the template class thing missing because this is specified^^
//throws since for secret cargo peeps shouldnt be trying to access the value of description
template<>
double Plane<SecretCargo>::calculateValue()
{
if ( cargo.size() == 0 ) {
    throw EmptyEx();
}
else {
    throw UnauthorisedEx(); 
    }
}

/*template<class T>
double Plane<T>::calculateValue()*/

template <>
string Plane<SecretCargo>::getDescription() // so it shouldnt be string Plane<SecretCargo>::getDescription ?^^
{
if ( cargo.size() == 0 ) {
    throw EmptyEx();//^^ with thr brakcets bc you thorw an object of the class right
}
else {
    throw UnauthorisedEx();
    }
}

#endif // __PLANE_H__