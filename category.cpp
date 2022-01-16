#include "category.h"

vector<Category> Category::cats;

Category::Category() {};

Category::Category(string name) : name(name)
{
    cats.push_back(*this);
}
