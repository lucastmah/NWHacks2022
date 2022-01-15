#ifndef EVENT_H
#define EVENT_H
#include <string>
#include <iostream>
#include <map>

using std::string;
using std::map;

class event
{
public:
    string name;
    int length; // in hours

    event(string name, int length);

    ~event();

private:
    static map<string, int> activities; // allows for pruning of 0 each week
};

#endif // EVENT_H
