#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <map>
#include <string>
#include "category.h"

using std::to_string;

class Event
{
public:
    string name;
    Category category;

    int start;
    int end;
    int length;

    Event(Category category, string name, int start, int end);
    string toString();

};

#endif // EVENT_H
