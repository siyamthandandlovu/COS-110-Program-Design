//Remember to add more test cases
//This main as-is does not test for everything

/*
Something to note for this specification is the following with regards to UML: a rectangle 
at the top right of the diagram indicates that the class is a template class, and it takes the parameter in the dotted square. 
Also take note that functions that are const are not labeled as such
on the UML diagrams, so read the descriptions of methods as well.
*/
#include <iostream>

/*#include "Passenger.h"
#include "Cargo.h"
#include "SecretCargo.h"
#include "Plane.h"*/

#include "Controller.h"

using namespace std;

int main()
{
//CREATE STATIC CARGO PASSENGER AND SECRET CARGO OBJECTS
cout << "\n\n STACK CREATE CARGO, PASSENGER AND SECRET CARGO OBJECTS\n\n";

cout << "\nTesting Passenger Objects\n";
Passenger p1("ID4" , 4.0 , 16.85);
cout << "P1 Passenger Description\n" << p1.describe();
cout << "P1 weight and value should be : " << p1.getWeight() << " " << p1.getValue() << endl;


cout << "\nTesting Cargo Objects\n";
Cargo c1(4.0 , 14.32);
cout << "C1 Cargo Description\n" << c1.describe();
cout << "C1 weight and value should be : " << c1.getWeight() << " " << c1.getValue() << endl;
cout << "Value should be " << 4.0*14.32 << endl;


cout << "\nTesting SecretCargo Objects\n";
SecretCargo s1(18882.3658498);
cout << "S1 SecretCargo Weight\n" << s1.getWeight();
//cout << "S1 weight and value should be : " << s1.getWeight() << " " << s1.getValue() << endl; // maybe get this back so it causes an exception to be thrown



//CREATE DYNAMIC CARGO PASSENGER AND SECRET CARGO OBJECTS
cout << "\n\n DYNAMIC CREATE CARGO, PASSENGER AND SECRET CARGO OBJECTS\n\n";

cout << "\nTesting Passenger Objects\n";
Passenger* ptPassenger1 = new Passenger("ID165" , 10.32 , 4.08);
cout << "ptPassenger1 Passenger Description\n" << ptPassenger1->describe();
cout << "ptPassenger1 weight and value should be : " << ptPassenger1->getWeight() << " " << ptPassenger1->getValue() << endl;


cout << "\nTesting Cargo Objects\n";
Cargo* ptCargo1 = new Cargo(0.6 , 0.98);
cout << "ptCargo1 Cargo Description\n" << ptCargo1->describe();
cout << "ptCargo1 weight and value should be : " << ptCargo1->getWeight() << " " << ptCargo1->getValue() << endl;
cout << "Value should be " << 15.6 * 0.98 << endl;


cout << "\nTesting SecretCargo Objects\n";
SecretCargo* ptSecretCargo1 = new SecretCargo (84.68);
cout << "ptSecretCargo1 SecretCargo Weight\n" << ptSecretCargo1->getWeight() << endl << endl;
//cout << "ptSecretCargo1 weight and value should be : " << ptSecretCargo1->getWeight() << " " << ptSecretCargo1->getValue() << endl; // maybe get this back so it causes an exception to be thrown
   
//cout << "\n\nThis should give you an exception thrown :\n";
//cout << "ptSecret Cargo getting descrioption and value " << ptSecretCargo1->describe() << "\n" << ptSecretCargo1->getValue() <<"\n\n\n\n";
    

//======================================
//now create a plane object and see if it works with just one of these types of objects
Plane<Cargo>* planeOfCargo = new Plane<Cargo>(4);
Controller<Cargo> controllerOfCargo(planeOfCargo);
Cargo* prCargoOfNull = NULL;
cout << "Using controller of cargo to load on plane: \n";
	cout<<controllerOfCargo.loadOnPlane(ptCargo1)<<endl;
	cout<<controllerOfCargo.loadOnPlane(ptCargo1)<<endl;
	cout<<controllerOfCargo.loadOnPlane(prCargoOfNull)<<endl;
	cout<<controllerOfCargo.loadOnPlane(ptCargo1)<<endl;
	cout<<controllerOfCargo.loadOnPlane(prCargoOfNull)<<endl;
	cout<<controllerOfCargo.loadOnPlane(prCargoOfNull)<<endl;
planeOfCargo->remove(ptCargo1);

cout <<"We removed and now there should be only five items; display : \n";
cout << controllerOfCargo.getPlaneContents() << endl;  
//controllerOfCargo.
planeOfCargo->remove(ptCargo1);
cout <<"\n a remove was made\n";
/*
planeOfCargo->remove(ptCargo1); 
planeOfCargo->remove(ptCargo1);  
planeOfCargo->remove(ptCargo1);
planeOfCargo->remove(ptCargo1);
*/

 
 
cout << "I removed everything and imma add a remove that fucks things up:\n";
//planeOfCargo->remove(ptCargo1);
//ok cool now how do i used controller to make the plane empty
cout <<"There were five items left but i had six removes lets see what the report from controllerOfCargo.getPlaneContents() looks like : \n";
cout << controllerOfCargo.getPlaneContents() << endl;



	cout<<"\n\n\n-----Testing Cargo-----"<<endl<<endl;

	Plane<Cargo>* plane = new Plane<Cargo>(200);
	Controller<Cargo> cc(plane);
	cout<<cc.loadOnPlane(new Cargo(50, 5))<<endl;
	cout<<cc.loadOnPlane(new Cargo(0.2, 500))<<endl;
	cout<<cc.loadOnPlane(new Cargo(30, 5))<<endl;
	cout<<cc.loadOnPlane(new Cargo(80.4, 1))<<endl;
	cout<<cc.loadOnPlane(new Cargo(50, 5))<<endl;

	cout<<"Total value: "<<cc.getTotalValue()<<endl;
	cout<<"Contents:\n"<<cc.getPlaneContents()<<endl<<endl;
 
	cout<<"-----Testing Passenger-----"<<endl<<endl;

	Plane<Passenger>* pplane = new Plane<Passenger>(2000);
	Controller<Passenger> pc(pplane);
	cout<<pc.loadOnPlane(new Passenger("ID0", 80.0, 1500))<<endl;
	cout<<pc.loadOnPlane(new Passenger("ID1", 70, 1000))<<endl;
	cout<<pc.loadOnPlane(new Passenger("ID2", 50, 1000))<<endl;
	cout<<pc.loadOnPlane(new Passenger("ID3", 100, 2000))<<endl;
	cout<<pc.loadOnPlane(new Passenger("ID4", 80, 1500))<<endl;

	cout<<"Total value: "<<pc.getTotalValue()<<endl;
	cout<<"Contents:\n"<<pc.getPlaneContents()<<endl;

	cout<<endl<<"-----Testing Secret Cargo-----"<<endl<<endl;

	Plane<SecretCargo>* splane = new Plane<SecretCargo>(100);
	Controller<SecretCargo> sc(splane);
	cout<<sc.loadOnPlane(new SecretCargo(20))<<endl;
	cout<<sc.loadOnPlane(new SecretCargo(10))<<endl;
	cout<<sc.loadOnPlane(new SecretCargo(50))<<endl;
	cout<<sc.loadOnPlane(new SecretCargo(5))<<endl;

	cout<<"Total value: "<<sc.getTotalValue()<<endl;
	cout<<"Contents:\n"<<sc.getPlaneContents()<<endl;
	//cplane

cout << "\n\n\n\n\n\n";
cout << "Testing The Undervalued Thing  \n";


cout<<"\n\n\n-----Testing Cargo Again -----"<<endl<<endl;

Plane<Cargo>* ThirdCargoPlane = new Plane<Cargo>(200);
Controller<Cargo> thirdCargoController(plane);
cout<<cc.loadOnPlane(new Cargo(50, 5))<<endl;
cout<<cc.loadOnPlane(new Cargo(0.2, 500))<<endl;
cout<<cc.loadOnPlane(new Cargo(30, 5))<<endl;
cout<<cc.loadOnPlane(new Cargo(80.4, 1))<<endl;
cout<<cc.loadOnPlane(new Cargo(50, 5))<<endl;
cout<<cc.loadOnPlane(new Cargo(0.01 , 0.01))<<endl;

cout<<"Total value via calculateValue: "<<cc.getTotalValue()<<endl;
//cout<<"Contents:\n"<<cc.getPlaneContents()<<endl<<endl;


	return 0;
}

//Expected output below
/*
-----Testing Cargo-----

Success
Success
Success
Success
Could not load item, above max weight by 10.6
Total value: 580.4
Contents:
Generic cargo <250> (50)
Generic cargo <100> (0.2)
Generic cargo <150> (30)
Generic cargo <80.4> (80.4)

-----Testing Passenger-----

Success
Success
Success
Success
Success
Total value: 7000
Contents:
ID0 <1500> (80)
ID1 <1000> (70)
ID2 <1000> (50)
ID3 <2000> (100)
ID4 <1500> (80)

-----Testing Secret Cargo-----

Success
Success
Success
Success
Total value: 0
Contents:
Not permitted
*/
