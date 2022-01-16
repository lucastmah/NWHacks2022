#include "event.h"

Event::Event(Category category, string name, int start, int end) {
    this->category = category;
    this->name = name;
    this->start = start;
    this->end = end;
    this->length = end - start;
}

string Event::toString(){
    string s = "Category: " + category.name + "\n";
    s += "Name: " + name + "\n";
    s += "Start: " + to_string(start) + "\n";
    s += "End: " + to_string(end) + "\n";
    return s;
}

