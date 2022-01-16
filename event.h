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

    ~Event();

private:
    static map<string, int> activities; // allows for pruning of 0 each week
};

map<string, int> Event::activities;

#endif // EVENT_H
