#include "category.h"

vector<Category> Category::cats;

Category::Category() {};

Category::Category(string name) : name(name) {};

/**
 * @brief Category::findCat returns an existing category with the given name
 * @param name that should match an existing category
 * @return category with given name
 */
Category Category::findCat(string name) {
    for (Category & c : Category::cats) {
        if (c.name == name) return c;
    }
    return Category();
}
