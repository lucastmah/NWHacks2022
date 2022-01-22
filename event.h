#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include "category.h"
#include <string>

using std::to_string;

/**
 * @brief The Event class
 */
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
