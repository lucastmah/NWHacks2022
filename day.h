#ifndef DAY_H
#define DAY_H

#include <vector>
#include "event.h"

using std::string;
using std::vector;

enum week { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY };

class Day
{
public:
    int weekday;
    int free;

    vector<Event> events;

    Day(int weekday);

    void addEvent(Event event);
};

#endif // DAY_H
