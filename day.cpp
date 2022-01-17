#include "day.h"

Day::Day(int year, int month, int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
}



void Day::addEvent(Event* event) {
    events.push_back(event);
}

