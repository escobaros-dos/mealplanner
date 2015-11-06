#include "meal.h"

Meal::Meal()
{
    MealName = " ";
    Date = " ";
    MealRecipe = Recipe();
    CalorieCount = 0;
    TotalCarbs = 0;
    TotalFatContent = 0;
    TotalProtien = 0;
    Proportions = 0;
}

Meal::Meal(QString date, int proportion, Recipe Mealrecipe)
{
    MealName = Mealrecipe.getName();
    Date = date;
    MealRecipe = Mealrecipe;
    Proportions = proportion;

    UpdateNutrition();
}

void Meal::ChangeDate(QString newDate)
{
    Date = newDate;
    return;
}

void Meal::ChangeName(QString newName) // maybe change these names to update names
{
    MealName = newName;
    return;
}

//template idea here too......
bool Meal::AddIngrediant(QString NewIngrediant) // QString or class?
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


void Meal::UpdateNutrition()
{
    //CalorieCount = Mealrecipe.GetTotalCalories();
    //TotalProtien = Mealrecipe.GetTotalProtien();
    //TotalFatContent = Mealrecipe.GetTotalFat();
    //TotalCarbs = Mealrecipe.GetTotalCarbs();
}

int Meal::GetMealCalories()
{
    return CalorieCount*Proportions;
}
int Meal::GetMealProtien()
{
    return TotalProtien*Proportions;
}
int Meal::GetMealFat()
{
    return TotalFatContent*Proportions;
}
int Meal::GetMealCarbs()
{
    return TotalCarbs*Proportions;
}

int Meal::GetNutrients(Nutriant n)
{
    int result = 0;
    UpdateNutrition();
    switch(n)
    {
    case Protien: result = GetMealProtien();
        break;
    case Carbs: result = GetMealCarbs();
        break;
    case Calorie: result = GetMealCalories();
        break;
    case Fat: result = GetMealFat();
        break;
    default: //uh oh.....
        break;

    }
    return result;
}



// function to return the nutriant values with the proportion in mind




