#include "recipe.h"

Recipe::Recipe()
{

}

Recipe::Recipe(QVector<Ingredient> ings, QVector<QString> step, QString name)
{
    this->ingredients=ings;
    this->steps=steps;
    this->name=name;

}

QString Recipe::serializeIngredients()
{
  
}

QString Recipe::getName() const
{
    return name;
}
