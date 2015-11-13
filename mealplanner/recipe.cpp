#include "recipe.h"

Recipe::Recipe()
{

}

Recipe::Recipe(QVector<Ingredient> ings, QString step, QString name)
{
    this->ingredients=ings;
    this->catSteps = step;
    this->name=name;

}

QString Recipe::serializeIngredients()
{
  
}

QString Recipe::getName() const
{
    return name;
}
