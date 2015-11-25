#include "recipe.h"

Recipe::Recipe()
{
    RecipeName = " ";
    CalorieCount = 0;
    TotalCarbs = 0;
    TotalFatContent = 0;
    TotalProtien = 0;
}

Recipe::Recipe(QVector<Ingredient> ings, QString step, QString name)
{
    IngredientsList = ings;
    DirectionsText = step;
    RecipeName = name;

   CalorieCount = 0;
   TotalCarbs = 0;
   TotalFatContent = 0;
   TotalProtien = 0;

   CalculateNutrition();
}

QString Recipe::getName() const
{
    return RecipeName;
}
void Recipe::CalculateNutrition()
{
    foreach(Ingredient I, IngredientsList.toList())
    {
        CalorieCount += I.getCalories();
        TotalCarbs += I.getCarbs();
        TotalFatContent += I.getFat();
        TotalProtien += I.getProtein();
    }
    return;
}


void Recipe::ChangeName(QString newName)
{
    RecipeName = newName;
    return;
}

bool Recipe::AddIngrediant(Ingredient NewIngrediant)
{
    //might want to add a check if already in the list, no duplicate ings???
    IngredientsList.push_back(NewIngrediant);
    return true;
}
bool Recipe::RemoveIngrediant(int index) // this function might only need an index param
{
    if(index > IngredientsList.size()) return false;

    IngredientsList.removeAt(index);
    return true;
}

QString Recipe::GetDirections() const
{
    return DirectionsText;
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
