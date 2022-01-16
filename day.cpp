#include "day.h"

Day::Day(int year, int month, int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
    this->free_time = 1440;
}



void Day::addEvent(Event* event) {
    events.push_back(event);
    free_time -= event->length;
}

