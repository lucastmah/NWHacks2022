#ifndef DAY_H
#define DAY_H

#include <vector>
#include "event.h"

using std::string;
using std::vector;

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
    int free_time;

    vector<Event*> events;

    Day(int year, int month, int day);

    void addEvent(Event* event);
};

#endif // DAY_H
