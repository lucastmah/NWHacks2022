#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <map>
#include "category.h"

using std::string;
using std::map;

class Event
{
public:
    string name;
    Category category;

    int start;
    int end;
    int length;

    Event(Category category, string name, int start, int end);

};

#endif // EVENT_H
