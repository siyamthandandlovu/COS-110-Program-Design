#include "Calendar.h"

using namespace std;

Calendar::Calendar() {
head = NULL;
}

Calendar::Calendar(vector<event_data> input) {
head = NULL;
for (int i = 0; i < input.size; i++)
{
    createEvent(input[i]);
}
}


Calendar::~Calendar() {
clearCalendar();
}

Event* Calendar::getUpcomingEvent(long int now) {

if (head == NULL)
{
    return NULL;//
}


Event* currEventNode;
currEventNode = head;
    while (currEventNode->start != now)
    {
        currEventNode = currEventNode->next;
    }

return currEventNode; 
}

vector<Event> Calendar::filterEvents(int* id, long int* start,long int* end, string* type) {
    
}

void Calendar::alterEvent(int id, long int* end, string* type) {
    
}

void Calendar::removeEvent(int id) {
    
}

void Calendar::createEvent(event_data data) {
    
}

void Calendar::clearCalendar() {
Event* currEventNode , prevEventNode;
currEventNode = head;
prevEventNode = NULL;

while (currEventNode != NULL && prevEventNode->next != NULL)
{
    prevEventNode = currEventNode;
    currEventNode = currEventNode->next;
    delete prevEventNode;
    
}

}

Event* Calendar::getFirstEvent() {
    
}

ostream operator<<(ostream out,Calendar calendar) {
    
}


