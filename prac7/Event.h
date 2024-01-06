#ifndef EVENT_H
#define EVENT_H

#include <string>
#include "Utils.h"

using namespace std;

class Event {
public:
long int start;
long int end;
int id;
std::string type;
Event* next;

Event(long int start , long int end , int id , string type);
~Event();

friend ostream operator<<(ostream out , Event event);

};

#endif // EVENT_H