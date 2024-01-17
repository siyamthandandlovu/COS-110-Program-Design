#ifndef DLL_H
#define DLL_H

#include "SortNode.h"

//SortList class Implementation here
template <class T>
class SortList {
private:
    bool ascending;
    SortNode<T>* head;
    SortNode<T>* tail;

public:
    SortList(bool asc);
    void add(SortNode<T>* a);
    SortNode<T>* remove( T val );
    void setAsc(bool a);
    void sort();
    std::string print();
    SortNode<T>* getHead();
    std::string debug();
    
};

#include "SortList.cpp"

#endif
/*
template <class T>
class SortNode {
protected:
    T value;
public:
    SortNode<T>* next;
    SortNode<T>* prev;

    SortNode( T );
    std::string print();
    T getValue();
};
*/