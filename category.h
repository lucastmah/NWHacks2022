#ifndef CATEGORY_H
#define CATEGORY_H

#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Category
{
public:
    string name;

    static vector<Category> cats;

    Category();
    Category(string name);
};

#endif // CATEGORY_H
