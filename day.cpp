#include "day.h"

Day::Day(int year, int month, int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
}

Day::~Day() {
    for (Event* e : events) {
        delete e;
    }
}

/**
 * @brief Day::addEvent adds a new event to the events member of day
 * @param event
 */
void Day::addEvent(Event* event) {
    events.push_back(event);
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
