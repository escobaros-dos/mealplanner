#include "ingredient.h"
#include <QDebug>

Ingredient::Ingredient()
{
    name="FOOBAR";
}

Ingredient::Ingredient(int protn, int ft, int crbs, int cals, QString n)
{
    name = n;
    calories = cals;
    carbs = crbs;
    fat = ft;
    protein = protn;
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
