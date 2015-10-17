#include "ingredient.h"

Ingredient::Ingredient()
{

}

QString Ingredient::getName() const {
    return name;
}

int Ingredient::getCalories() const {
    return calories;
}

int Ingredient::getCarbs() const {
    return carbs;
}

int Ingredient::getFat() const {
    return fat;
}

int Ingredient::getProtein() const {
    return protein;
}
