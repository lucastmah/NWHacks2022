#include "event.h"

Event::Event(Category category, string name, int start, int end) {
    this->category = category;
    this->name = name;
    this->start = start;
    this->end = end;
    this->length = end - start;
}
