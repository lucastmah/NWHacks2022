#include "day.h"

Day::Day(int year, int month, int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
    this->free_time = 1440;
}

Day::~Day() {
    for (Event* e : events) {
        delete e;
    }
}

/**
 * @brief Day::addEvent
 * @param event
 */
void Day::addEvent(Event* event) {
    events.push_back(event);
    free_time -= event->length;
}

/**
 * @brief Day::toString
 * @return Information about this Day object in a fixed format
 */
string Day::toString(){
    string s = "Year: " + to_string(year) + "\n";
    s += "Month: " + to_string(month) + "\n";
    s += "Day: " + to_string(day) + "\n";
    return s;
}
