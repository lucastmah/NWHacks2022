#include "event.h"

event::event(string name, int length) {
    this->name = name;
    this->length = length;
    activities[name]++;
    }

event::~event() {
    activities[name]--;
}

