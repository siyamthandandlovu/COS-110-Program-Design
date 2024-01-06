#ifndef __NODE_H__
#define __NODE_H__
#include <cstddef>
#include "Node.h"

template<class T>
Node<T>::Node(T data)
{
    this->data = data;
    this->next = NULL;
}

template<class T>
T Node<T>::getData()
{
    return data;
}

template<class T>
Node<T>* Node<T>::getNext()
{
    return next;
}

template<class T>
void Node<T>::setNext(Node<T>* ptr)
{
    next = ptr;
}

#endif // __NODE_H__