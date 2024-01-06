#ifndef __SORTNODE_H__
#define __SORTNODE_H__

//#include <iostream> should i have it here for submimssion?
using namespace std;


template<class T>
SortNode<T>::SortNode(T val)
{
    this->value = val;
}

template<class T>
std::string SortNode<T>::print()
{
    /*if (this == NULL)
    {
        //std::cout << "SortNode<T>::print() || we cannot print anything since this node points to null";
        //return "Printing SortNode : POINTS TO NULL";
        //return "POINTS TO NULL";
        return "NULL";
    }*/

 if (this != NULL)
{
    stringstream sss;
    //std::cout << getValue();
    sss << getValue();//imake 
    return sss.str();
}
return "";//i will haave to remove this ???? but what should we check for vele?
}

template<class T>
T SortNode<T>::getValue()
{
    /*if (this == NULL)
    {
       // std::cout << "SortNode<T>::getValue() || we cannot return anything since this node points to null";
    }*/
    return value;
}


#endif // __SORTNODE_H__