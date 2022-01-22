#include "category.h"

vector<Category> Category::cats;

Category::Category() {};

Category::Category(string name) : name(name) {};

/**
 * @brief Category::findCat
 * @param name
 * @return
 */
Category Category::findCat(string name) {
    for (Category & c : Category::cats) {
        if (c.name == name) return c;
    }
    return Category();
}
