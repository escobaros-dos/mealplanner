#include "recipe.h"

Recipe::Recipe()
{
    rname = " ";
    CalorieCount = 0;
    TotalCarbs = 0;
    TotalFatContent = 0;
    TotalProtien = 0;
}


Recipe::Recipe(QVector<Ingredient> ings, QString step, QString name)
{
    ingredients = ings;
    catSteps = step;
    rname = name;

    CalorieCount = 0;
    TotalCarbs = 0;
    TotalFatContent = 0;
    TotalProtien = 0;


    CalculateNutrition();

}

QString Recipe::getName() const
{
    return rname;
}

void Recipe::CalculateNutrition()
{

    foreach(Ingredient I, ingredients.toList())
    {
        CalorieCount += I.calories;
        TotalCarbs += I.carbs;
        TotalFatContent += I.fat;
        TotalProtien += I.protein;
    }
    return;
}


void Recipe::ChangeName(QString newName) // maybe change these names to update names
{
    rname = newName;
    return;
}

bool Recipe::AddIngrediant(Ingredient NewIngrediant) // QString or class?
{
    //might want to add a check if already in the list, no duplicate ings???
    ingredients.push_back(NewIngrediant);
    //UpdateNutrition();
    return true;
}
bool Recipe::RemoveIngrediant(int index) // this function might only need an index param
{
    if(index > ingredients.size()) return false;

    ingredients.removeAt(index);
    //UpdateNutrition();
    return true;
}

//for viewing


QString Recipe::GetDirections() const
{
    return catSteps;
}

int Recipe::GetCalories()
{
    return CalorieCount;
}
int Recipe::GetProtien()
{
    return TotalProtien;
}
int Recipe::GetFat()
{
    return TotalFatContent;
}
int Recipe::GetCarbs()
{
    return TotalCarbs;
}
