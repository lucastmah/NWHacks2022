#include "day.h"

Day::Day(int weekday) : weekday(weekday)
{
    this->free = 1440;
}

void Day::addEvent(Event event) {
    events.push_back(event);
}
