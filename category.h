#ifndef CATEGORY_H
#define CATEGORY_H

#include <iostream>
#include <vector>

using std::string;
using std::vector;

class Category
{
public:
    static vector<Category> cats;

    Category();
    Category(string cat_name);

    string name();
    string cat_name;
};

vector<Category> Category::cats;

#endif // CATEGORY_H
