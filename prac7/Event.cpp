#include "Event.h"

using namespace std;


Event::Event(long int start , long int end , int id , std::string type)
{
    this->start = start;
    this->end = end;
    this->id = id;
    this->type = type;

}


Event::~Event() {
std::cout << "Event::~Event()\n";
}

ostream operator<<(ostream out , Event event)
{
    out << event.type << " " << unix_to_string(start) << "->" << unix_to_string(end);
    cout << out.str();
    return out;
}