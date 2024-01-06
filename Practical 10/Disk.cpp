#ifndef __DISK_H__
#define __DISK_H__

#include "Disk.h"

template<class T>
Disk<T>::Disk(T label)
{
    this->label = label;
}

template<class T>
T Disk<T>::getLabel() const
{
    return label;
}

#endif // __DISK_H__