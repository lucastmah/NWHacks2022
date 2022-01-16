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

    Day(int weekday);
    vector<Event> events;

};

#endif // DAY_H
