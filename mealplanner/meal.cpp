#include "meal.h"

Meal::Meal()
{
    MealName = " ";
    Date = " ";
    Recipe = NULL;
    CalorieCount = 0;
}

Meal::Meal(string name, string date, Recipe Mealrecipe)
{
    MealName = name;
    Date = date;
    MealRecipe = Mealrecipe;

    //CalorieCount = Mealrecipe.GetTotalCalories();
    //TotalProtien = Mealrecipe.GetTotalProtien();
}

bool Meal::ChangeDate(string newDate)
{
    if(!Valid(newDate)) return false;
    Date = newDate;
    return true;
}

bool Meal::ChangeName(string newName)
{
    if(!Valid(newName)) return false;
    MealName = newName;
    return true;
}


//NOTE: C# SUPIRIORITY HERE, DELAGATES OWN HERE.  Meal::PerformIngrediantOperation(string ingredinant, delagate operation)
bool Meal::AddIngrediant(string NewIngrediant)
{
    if(!Valid(NewIngrediant)) return false; // the valid checks might not be in the meal class at final build

    this->MealRecipe.Add(NewIngrediant);
    return true;

}

bool Meal::RemoveIngrediant(string TargetIngrediant)
{
    if(!Valid(TargetIngrediant)) return false;

    this->MealRecipe.Remove(TargetIngrediant);
    return true;
}

void Meal::ListRecipe()
{
    this->MealRecipe.Display();
}


