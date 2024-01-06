#include <iostream>
#include <string>

#include "Exception.h"
#include "Disk.cpp"
#include "TowersOfHanoi.cpp"
#include "IterativeSolution.cpp"
#include "RecursiveSolution.cpp"
using namespace std;

/*
template <class T>
class Disk
{
private:
    T label;
public:
    Disk(T label);
    T getLabel() const;
};*/ 

void testA() {

 
//cout << "Main || Creating an object of type IterativeSolution\n";
IterativeSolution<int>* objIterative1 = new IterativeSolution<int>(1 , 3);
cout << "Main || Creating an object of type IterativeSolution\n";

try 
{
objIterative1->addDisk((20) , 1);
cout << "Main || added one thingie\n";
objIterative1->addDisk((18), 1);
objIterative1->addDisk((16) , 1);
objIterative1->addDisk((14) , 1);
objIterative1->addDisk((12) , 1);
objIterative1->addDisk((10) , 1);
objIterative1->addDisk((8) , 1);
}
catch(...)
{
    cout << "Main || Error in Trying to add shit\n";
}


cout << "Main || objIterative1 Stack Display:\n";
while (objIterative1->getTower(1)->empty() == false) {
cout << "Address : " << objIterative1->getTower(1)->top() << " Value : "<< objIterative1->getTower(1)->top()->getLabel() <<"\n";
    objIterative1->getTower(1)->pop();
}  

try
{
objIterative1->addDisk((20) , 1);
objIterative1->addDisk((18), 1);
objIterative1->addDisk((16) , 1);
objIterative1->addDisk((14) , 1);
objIterative1->addDisk((12) , 1);
objIterative1->addDisk((10) , 1);
objIterative1->addDisk((8) , 1);
}
catch(...)
{
    cout << "Main || Error in Trying to add shit\n";
}

//wait it is supposed to be ascending or something?? 
cout << "Main || Added Disks to IterativeSolution object *AGAIN*\n";

if (objIterative1->validateGame() == true)
{
    cout << "Main || objIterative1->validateGame() == TRUE\n";
}
else cout << "Main || objIterative1->validateGame() == FALSE\n";

//    void moveDisk(int dep , int dest);
//    void addDisk(T diskData , int tower);

/*
empty() – Returns whether the stack is empty – Time Complexity : O(1) 
size() – Returns the size of the stack – Time Complexity : O(1) 
top() – Returns a reference to the top most element of the stack – Time Complexity : O(1) 
push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1) 
pop() – Deletes the top most element of the stack – Time Complexity : O(1) 
*/

if (objIterative1->getTower(1) != NULL && objIterative1->getTower(1)->empty()==false)
    cout << "Success : Tower 1 points to a stack AND its not empty \n";
else if (objIterative1->getTower(1) == NULL)
    cout << "Try Again : Tower 1 points to NULL\n";
else if (objIterative1->getTower(1)->empty()==false)
    cout << "Try Again : Tower 1 points to an empty stack\n";
else
    cout << "Try Again : Tower 1 is fucked up and idk why\n";


if (objIterative1->getTower(2) != NULL && objIterative1->getTower(2)->empty()==false)
    cout << "Success : Tower 2 points to a stack AND its not empty \n";
else if (objIterative1->getTower(2) == NULL)
    cout << "Try Again : Tower 2 points to NULL\n";
else if (objIterative1->getTower(2)->empty()==false)
    cout << "Try Again : Tower 2 points to an empty stack\n";
else
    cout << "Try Again : Tower 2 is fucked up and idk why\n";


if (objIterative1->getTower(3) != NULL && objIterative1->getTower(3)->empty()==false)
    cout << "Success : Tower 3 points to a stack AND its not empty \n";
else if (objIterative1->getTower(3) == NULL)
    cout << "Try Again : Tower 3 points to NULL\n";
else if (objIterative1->getTower(3)->empty()==false)
    cout << "Try Again : Tower 3 points to an empty stack\n";
else
    cout << "Try Again : Tower 3 is fucked up and idk why\n";

// else cout << "Try Again : Tower 1 points to a null OR it points to something empty\n";




cout << "\n========================================================\n";
}

int main(){
cout << "Begin Testing : Integers\n";
testA();
}