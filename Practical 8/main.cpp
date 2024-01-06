#include "SortList.h"
#include <iostream>

//Add any tests you want (as you should)
//This prac does not check memory usage, and even this main does not really delete allocated memory
//Keep that in mind should you wish to use valgrind
//Also note that memory management is not the focus of this practical, so NO DESTRUCTORS ARE INVOLVED
//If you create destructors, you will get an abnormal exit status on fitchfork

using namespace std;

int main()
{
	SortList<int>* ll = new SortList<int>(1);
	ll->add(new SortNode<int>(5));
	ll->add(new SortNode<int>(50));
	ll->add(new SortNode<int>(0));
	ll->add(new SortNode<int>(3));
	ll->add(new SortNode<int>(28));
	ll->add(new SortNode<int>(907));
	ll->add(new SortNode<int>(1));


	cout<<"Initial print"<<endl<<ll->print()<<endl;
//	ll->remove(3);
	ll->sort();
	cout<<"Sorted"<<endl<<ll->print()<<endl;
	cout<<"Removed: "<<ll->remove(50)->print()<<endl<<endl;
	cout<<"Removed: "<<ll->remove(907)->print()<<endl<<endl;

	cout<<"Print after removal"<<endl<<ll->print()<<endl;
	ll->setAsc(0);

	cout<<"Descending"<<endl<<ll->print()<<endl;

	delete ll;

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
