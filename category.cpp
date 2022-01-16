#include "category.h"

vector<Category> Category::cats;

Category::Category() {};

Category::Category(string cat_name) : cat_name(cat_name)
{
    cats.push_back(*this);
}

string Category::name() {
    return cat_name;
}
