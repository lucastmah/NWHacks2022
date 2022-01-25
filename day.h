#ifndef DAY_H
#define DAY_H

#include <vector>
#include "event.h"
#include <iostream>
#include <string>

using std::string;
using std::vector;
using std::to_string;
using std::cout;
using std::endl;

/**
 * @brief The Day class
 * @variable year, month and day represent the date of this day
 */
class Day
{
public:
    int year, month, day;

    vector<Event*> events;

    Day(int year, int month, int day);
    ~Day();

    void addEvent(Event* event);
    string toString();
};

#endif // DAY_H
