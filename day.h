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

enum week { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY };

/**
 * @brief The Day class
 * @variable year, month and day represent the date of this day
 * @variable free_time holds how much free time is left (in minutes)
 */
class Day
{
public:
    int year, month, day, weekday;

    vector<Event*> events;

    Day(int year, int month, int day);
    ~Day();

    void addEvent(Event* event);
    string toString();
};

#endif // DAY_H
