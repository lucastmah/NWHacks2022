#include "day.h"

Day::Day(int weekday) : weekday(weekday)
{
    this->free_time = 1440;
}

void Day::addEvent(Event event) {
    events.push_back(event);
    free_time -= event.length;
}
