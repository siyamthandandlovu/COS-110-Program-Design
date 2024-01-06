#ifndef __STACK_H__
#define __STACK_H__
#include <cstddef>
#include "Stack.h"

template<class T>
Stack<T>::Stack()
{
    top = NULL;
}

template<class T>
Stack<T>::~Stack()
{
    Node<T>* currNode = top;
    while (top != NULL)//isnt this a problem since setting node
    {
        currNode = top;
        //std::cout << "~Stack || Deletion : " << top->getData() << "\n";
        top = top->getNext();//?? will never work since we dont have the other items in the stack
        delete currNode;
        currNode = top;
    }
}

template<class T>
void Stack<T>::push(T data)
{
    //create a dynamic node val
    Node<T>* newNode = new Node<T> (data);//??? waaaat
    if (this->top == NULL)
    {
        top = newNode;
        //newNode->getNext() = NULL;
        newNode->setNext(NULL);// = NULL;
    //std::cout << "Stack || Push || Pushed on empty stack, data == " << data << "\n";        
    return;
    }
    //otherwise the stack has values and you just add things
    //newNode->getNext() = top;
    newNode->setNext(top);// = top;
    top = newNode;
    //std::cout << "Stack || Push || Additional node, data == " << data << "\n";
}

template<class T>
Node<T>* Stack<T>::pop()
{
    if (top == NULL)
    {
        return NULL;
    }
    
    Node<T>* tempRemove = top;
    top = top->getNext();
    //std::cout << "\nStack pop || Removed Node of this value : " << tempRemove->getData();
    return tempRemove;

    //top = NULL; wouldnt work
}

template<class T>
Node<T>* Stack<T>::getTop()
{
    return top;
}

template<class T>
int Stack<T>::size()
{
    Node<T>* currNode = top;
    int count = 0;
    while (currNode != NULL)//isnt this a problem since setting node
    {
        count++;
        currNode = currNode->getNext();
    }
    return count;
    
}

template<class T>
Stack<T>* Stack<T>::reverse()
{
    Stack<T>* ptNewStack = new Stack<T>;
    //go to head
    //so deep copies??

    Node<T>* currNode = this->top;
    //get the size of the array
    while (currNode != NULL)
    {
        ptNewStack->push( currNode->getData() );
        currNode = currNode->getNext();
    }
    
   // ptNewStack->top = ptNewNodeTop;
    return ptNewStack;
}

template<class T>
bool Stack<T>::contains(T data)
{
    Node<T>* currNode = top;
    bool bContains = false;
    while (currNode != NULL && bContains == false )//isnt this a problem since setting node
    {
        if (currNode->getData() == data)
        {
            bContains = true;
        }
        
        currNode = currNode->getNext();
    }
    return bContains;
}

template<class T>
bool Stack<T>::isEmpty() 
{
    if (this->size() == 0)
    {
        return true;
    }
    return false;
}

#endif // __STACK_H__