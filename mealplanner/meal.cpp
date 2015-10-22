#include "meal.h"

Meal::Meal()
{
    MealName = " ";
    Date = " ";
    MealRecipe = new Recipe();
    CalorieCount = 0;
    TotalCarbs = 0;
    TotalFatContent = 0;
    TotalProtien = 0;

}

Meal::Meal(string name, string date, Recipe Mealrecipe)
{
    MealName = name;
    Date = date;
    MealRecipe = Mealrecipe;

    UpdateNutrition();
}

void Meal::ChangeDate(string newDate)
{
    Date = newDate;
    return;
}

void Meal::ChangeName(string newName)
{
    MealName = newName;
    return;
}

//template idea here too......
bool Meal::AddIngrediant(QString NewIngrediant) // string or class?
{
    //MealRecipe.IngrediantsList.Add(NewIngrediant);
    UpdateNutrition();
    return true;
}

bool Meal::RemoveIngrediant(QString TargetIngrediant)
{

    // need a database function that returns bool if found or not
    //if(!Found(TargetIngrediant) return DisplayError(IngrediantErr);
    //else

    //MealRecipe.IngrediantsList.Remove(TargetIngrediant);
    UpdateNutrition();

    //calling this database function with change the meals recipe so it will reflect in
    //any recipe functions in this class and others.

    return true;
}

//return a vector of q strings?????

QVector<QString>& Meal::ListRecipe()
{
    // return DataBaseManager.getRecipe(MealRecipe.RecipeName);
}


float Meal::UpdateNutrition()
{
    //CalorieCount = Mealrecipe.GetTotalCalories();
    //TotalProtien = Mealrecipe.GetTotalProtien();
    //TotalFatContent = Mealrecipe.GetTotalFat();
    //TotalCarbs = Mealrecipe.GetTotalCarbs();
}




