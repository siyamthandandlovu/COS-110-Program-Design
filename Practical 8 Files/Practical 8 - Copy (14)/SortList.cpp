using namespace std;

template<class T>
SortList<T>::SortList(bool asc)
{
    ascending = asc;
}

template<class T>
void SortList<T>::add(SortNode<T>* a)
{
    ////std::cout << "void SortList<T>::add(SortNode<T>* a) \n";
    if (a == NULL) return;
    
    if (head == NULL)//empty list
    {
    head = a; 
    tail = a;

    a->prev = NULL;
    a->next = NULL;
    ////std::cout << "This element was added AS THE HEAD " << head->getValue() << "\n";
    //std::cout << "Addition || List was empty, we added one element as head: " << a->print() << "\n";
    }//and carry on
    //else if (head->next == NULL || head == tail) { // only has ONE element
    else if (head == tail && head != NULL && tail != NULL) {
    head->next = a;//heads next is no longer null

    a->next = NULL;//bc its the tail now since we add it to the end
    a->prev = head;//what tial points to OR point to what head points to vele

    tail = a;//since a is the new tail

    //std::cout << "Addition || Only had one element, added this " << a->print() << " TAIL == "<< tail->print() << " PREV == "<< a->prev->print() << " NEXT == "<< a->next->print() <<  "\n";
    }
    else
    {
        a->next = NULL;//bc its now the last elemenet
        a->prev = tail;//what tial points to
        //a->prev->next = a;
        tail->next = a;//same as above

        tail = a;//since a is the new tail 
        //std::cout << "Addition || Many elements, added this " << a->print() << " TAIL == "<< tail->print() << " PREV == "<< a->prev->print() << " NEXT == "<< a->next->print() << "\n";
    }
    //this->print();//how tf would this even work tho, how did this run??
    //std::cout << "Addition || The list now : " << this->print() << "\n";
}

template<class T>
SortNode<T>* SortList<T>::remove(T val) {
    SortNode<T>* ptCurrNode = NULL;
    ptCurrNode = head;

//    while (ptCurrNode != tail && ptCurrNode->getValue() != val) {//before i said curr node not = null
    while (ptCurrNode != NULL && ptCurrNode->getValue() != val) { 
        ptCurrNode = ptCurrNode->next;
    }

    if (ptCurrNode == NULL) {
        //std::cout << "List Remove || The value was not found\n";
       // return ptCurrNode; //neh?
    }  //different for removing from head, middle and end bc of tail update and shit
    else if ( head == tail ) //if head an tail point to the same thing only one item in the list
    {
        head = NULL;
        tail = NULL;
        //std::cout << "List Remove || Only one value here\n";
        //return ptCurrNode;
    }
    else if (ptCurrNode == head)//if we are deleting at the beginning
    {
        head = head->next;
        head->prev = NULL;
        //std::cout << "List Remove || Removing at the head\n";
        //return ptCurrNode;
    }
    else if (ptCurrNode == tail) //if there is one element in the list then the prev bracket 
    {
      
        tail = tail->prev;//and make it point to null innit?
       tail->next = NULL; 
        //std::cout << "List Remove || Removing at the tail "<< "\n";

       // return ptCurrNode;
    }
    else //removing shit from the middle
    {
        ptCurrNode->prev->next = ptCurrNode->next;
        ptCurrNode->next->prev = ptCurrNode->prev;
        //std::cout << "List Remove || Removing in the middle "<< "\n";
    }

    return ptCurrNode;
}

template<class T>
void SortList<T>::setAsc(bool a)
{
ascending = a;
sort();
}

template<class T>
void SortList<T>::sort() {
if (head == tail || head->next == NULL || head == NULL)//there is only one element OR the list is empty
{
    return;
}

//CRRATE NEW LIST OBJECT
SortList<T>* ptNewListObject = new SortList<T>(this->ascending); 

int count = 0;
int traversal = 0;
SortNode<T>* ptCurrNode = this->head;

if (ascending == true) //
{ 
//go through each and find the lists while
//std::cout << "List Sort || Sorting list in ascending order\n";
SortNode<T>* ptSmallestNodeValue = NULL;

while (this->head != NULL && this->tail != NULL)//meaning while our og list has not been empteed
{

ptSmallestNodeValue = this->head;
ptCurrNode = this->head;

    //keep finding the smallest value in the entire current linked list
        //while (ptCurrNode != tail)//for the sake of traversal
        traversal = 0;
        while (ptCurrNode != NULL)//while ptCurrNode is not at the tail
        {
            //std::cout << "List Sort || While Loop " << ++traversal << "\tSmallest Val : " << ptSmallestNodeValue->print() << " Current Node Val : "<< ptCurrNode->print() << "\n";

            if ( ptCurrNode->getValue() < ptSmallestNodeValue->getValue() )    
            {
                ptSmallestNodeValue = ptCurrNode;
                //std::cout << "List Sort || While loop : Smallest Node value right now : "<< ptSmallestNodeValue->print() << "\n";
            }        
            ptCurrNode = ptCurrNode->next;    
        }


SortNode<T>* ptRemovedNode = this->remove(ptSmallestNodeValue->getValue());
//std::cout << "List Sort || This is the list after removing the smallest node " << ptRemovedNode->print() << " : "<< this->print() << "\n";

ptNewListObject->add(ptRemovedNode);
//std::cout << "List Sort || This is the NEW LIST list after ADDING the smallest node : "<< ptNewListObject->print() << "\n";

////std::cout << "List Sort || CODE EXECUTED : ptNewListObject->add(this->remove(ptCurrNode->getValue()));\n";
//ptSmallestNodeValue = this->head;
//std::cout << "End of iteration " << ++count << " and we reset ptSmallestNodeValue " << ptSmallestNodeValue->print() << " and we are returning to beginning\n\n\n";
}
    
}
else if (ascending == false)
{
//go through each and find the lists while
//std::cout << "List Sort || Sorting list in descending order\n";
SortNode<T>* ptLargestNodeValue = head;

while (this->head != NULL && this->tail != NULL)//meaning while our og list has not been empteed
{
//keep finding the largest value in the entire current linked list
//remove the vlaue from current linked list
//add that to the new linked list
ptLargestNodeValue = this->head;
ptCurrNode = this->head;


        traversal = 0;
        while (ptCurrNode != NULL)//while ptCurrNode is not at the tail
        {
            //std::cout << "List Sort || While Loop " << ++traversal << "\tLargest Val : " << ptLargestNodeValue->print() << " Current Node Val : "<< ptCurrNode->print() << "\n";

            if ( ptCurrNode->getValue() > ptLargestNodeValue->getValue() )    
            {
                ptLargestNodeValue = ptCurrNode;
                //std::cout << "List Sort || While loop : Largest node value right now : "<< ptLargestNodeValue->print() << "\n";
            }        
            ptCurrNode = ptCurrNode->next;    
        }


SortNode<T>* ptRemovedNode = this->remove(ptLargestNodeValue->getValue());
//std::cout << "List Sort || This is the list after removing the largest node " << ptRemovedNode->print() << " : "<< this->print() << "\n";

ptNewListObject->add(ptRemovedNode);
//std::cout << "List Sort || This is the NEW LIST list after ADDING the largest node : "<< ptNewListObject->print() << "\n";


//std::cout << "End of iteration " << ++count << " and we reset ptLargestNodeValue " << ptLargestNodeValue->print() << " and we are returning to beginning\n\n\n";
}
 
}

//std::cout << "Sort List || Changing the head and tail of this list to point to the new one \n";
this->head = ptNewListObject->head;
this->tail = ptNewListObject->tail;


}// end of 


template<class T>
std::string SortList<T>::print() {
    if (head == NULL) // empty list
    {
        //std::cout << "List print()  || The list is empty\n";
        return "";
    }
    if (head == tail)
    {
        ////std::cout << "List print() || One Node "<< head->print() <<"\n";
        return head->print();
    }//if head->next == tail ie the next nodes address is stored in the tail poitner then there are two 
    
    
    std::stringstream sss;
    SortNode<T>* ptCurrNode = head;

    while ( ptCurrNode != tail ) //check against tail right?//same as ptCurrNode->next != tail
    {   

        sss << ptCurrNode->print() << ",";
        ptCurrNode = ptCurrNode->next;
    }

    sss << tail->print();

    return sss.str();
}

template<class T>
SortNode<T>* SortList<T>::getHead() {
    return head;
}

template<class T>
std::string SortList<T>::debug() {
    SortNode<T>* ptCurrNode = head;

    stringstream ss;
    int count = 0;
    //std::cout << "***********************\nDEBUG FUNCTION\n***********************\n";
    ss << "COUNT" << "\t"<< "PREV" << "\t" << "CURRENT" << "\t" << "NEXT" << "\n";
    while ( ptCurrNode != NULL ) //check against tail right?
    {

    ss << ++count << "\t"<< ptCurrNode->prev->print() << "\t" << ptCurrNode->print() << "\t" << ptCurrNode->next->print() << "\n";

    ptCurrNode = ptCurrNode->next;
    }

    return ss.str();
}