#include <iostream>
#include "SortList.h"
  
//Add any tests you want (as you should)
//This prac does not check memory usage, and even this main does not really delete allocated memory
//Keep that in mind should you wish to use valgrind
//Also note that memory management is not the focus of this practical, so NO DESTRUCTORS ARE INVOLVED
//If you create destructors, you will get an abnormal exit status on fitchfork

using namespace std;
          
int main()     
{ 
	cout << "Start\n"; 
	SortList<int>* ll = new SortList<int>(1);
	cout << "Created new list in main funciton\n";
	ll->add(new SortNode<int>(356));
	ll->add(new SortNode<int>(5)); //cout << "Main : added a new node\n"; 
	ll->add(new SortNode<int>(50));
	ll->add(new SortNode<int>(0));
	ll->add(new SortNode<int>(200));
	ll->add(new SortNode<int>(14));
	ll->add(new SortNode<int>(5));
	ll->add(new SortNode<int>(3));
	ll->add(new SortNode<int>(28));
	ll->add(new SortNode<int>(356));
	ll->add(new SortNode<int>(907));
	ll->add(new SortNode<int>(1));
	ll->add(new SortNode<int>(1));  

 
	cout << "Initial print before removals"<< endl <<ll->print()<<endl;

	cout << "Testing Removals\n";
	ll->remove(13);
	ll->remove(3);
	cout << "Print after removals"<< endl <<ll->print()<<endl;
	cout << "\nDisplay ll - debug function\n";
	cout << ll->debug() << endl;

cout << "\n=========================================================================\n";
cout << "Testing list printings \n";

SortList<int>* ptListA = new SortList<int>(false); 
cout << "Printing ptList A - EMPTY\n";
cout << ptListA->print() << "\n";

ptListA->remove(3);
cout << "Printing ptList A - After removing empty list\n";
cout << ptListA->print() << "\n";
 
ptListA->add(new SortNode<int>(32));
ptListA->add(new SortNode<int>(97));
ptListA->add(new SortNode<int>(1));


cout << "Printing ptList A - 3 ADDED ELEMENTS\n";
cout << ptListA->print() << "\n";
cout << "\nDisplay ptListA - debug function\n";
cout << ptListA->debug() << endl;
cout << "=========================================================================\n";

 
  

cout << "Main || Display ll list before sorting - debug function \n";
cout << ll->debug() << endl;
ll->sort();


cout<<"Printing array after sorting : "<<endl<<ll->print()<<endl;
cout<<"List print after Removed 50  : "<<ll->remove(50)->print()<<endl<<endl;
cout<<"List print after Removed 907 : "<<ll->remove(907)->print()<<endl<<endl;

cout<<"Print after ALL removals"<<endl<<ll->print()<<endl;
ll->setAsc(0);
ll->sort(); 

cout<<"Print of ll list in descending order"<<endl<<ll->print()<<endl;

delete ll;




cout << "\n\n\n=========================================================================\n";

	cout << "New testing with doubles instead\n"; 
	SortList<double>* llDoubles = new SortList<double>(1);
	cout << "Created new list in main funciton\n";
	llDoubles->add(new SortNode<double>(35.6));
	llDoubles->add(new SortNode<double>(5.36)); //cout << "Main : added a new node\n"; 
	llDoubles->add(new SortNode<double>(50.5));
	llDoubles->add(new SortNode<double>(0.2));
	llDoubles->add(new SortNode<double>(20.30));
	llDoubles->add(new SortNode<double>(1.14));
	llDoubles->add(new SortNode<double>(5.0));
	llDoubles->add(new SortNode<double>(3));
	llDoubles->add(new SortNode<double>(28));
	llDoubles->add(new SortNode<double>(3.56));
	llDoubles->add(new SortNode<double>(90.7));
	llDoubles->add(new SortNode<double>(1));
	llDoubles->add(new SortNode<double>(1));  

 
	cout << "Initial print before removals"<< endl <<llDoubles->print()<<endl;

	cout << "Testing Removals\n";
	llDoubles->remove(13);
	llDoubles->remove(3);
	cout << "Print after removals"<< endl <<llDoubles->print()<<endl;
	cout << "\nDisplay llDoubles - debug function\n";
	cout << llDoubles->debug() << endl;

 
  

cout << "Main || Display llDoubles list before sorting - debug function \n";
cout << llDoubles->debug() << endl;
llDoubles->sort();


cout<<"Printing array after sorting : "<<endl<<llDoubles->print()<<endl;
cout<<"List print after Removed 50  : "<<llDoubles->remove(50)->print()<<endl<<endl;
cout<<"List print after Removed 907 : "<<llDoubles->remove(907)->print()<<endl<<endl;

cout<<"Print after AllDoubles removals"<<endl<<llDoubles->print()<<endl;
llDoubles->setAsc(0);
llDoubles->sort(); 

cout<<"Print of llDoubles list in descending order"<<endl<<llDoubles->print()<<endl;

delete llDoubles;


cout << "=========================================================================\n";


cout << "\n\n\n\n\nMy own testing\n";
return 0;
} 

//Expected output
/*
Initial print
5,50,0,3,28,907,1

Sorted
0,1,3,5,28,50,907

Removed: 50
Removed: 907

Print after removal
0,1,3,5,28

Descending
28,5,3,1,0

*/
