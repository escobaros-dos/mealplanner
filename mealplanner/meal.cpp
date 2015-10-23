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
    Proportions = 0;
}

Meal::Meal(string name, string date, int proportion, Recipe Mealrecipe)
{
    MealName = name;
    Date = date;
    MealRecipe = Mealrecipe;
    Proportions = proportion;

    UpdateNutrition();
}

void Meal::ChangeDate(string newDate)
{
    Date = newDate;
    return;
}

void Meal::ChangeName(string newName) // maybe change these names to update names
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

    // need a database function that returns bool if found or not....maybe
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

float Meal::GetCalories()
{
    return CalorieCount*Proportions;
}
float Meal::GetProtien()
{
    return TotalProtien*Proportions;
}
float Meal::GetFat()
{
    return TotalFatContent*Proportions;
}
float Meal::GetCarbs()
{
    return TotalCarbs*Proportions;
}

float Meal::GetNutrients(Nutriant n)
{
    float result = 0;
    UpdateNutrition();
    switch(n)
    {
    case Protien: result = GetProtien();
        break;
    case Carbs: result = GetCarbs();
        break;
    case Calorie: result = GetCalories();
        break;
    case Fat: result = GetFat();
        break;
    default: //uh oh.....

    }
    return result;
}



// function to return the nutriant values with the proportion in mind




