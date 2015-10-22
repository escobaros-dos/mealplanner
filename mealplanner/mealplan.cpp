#include "mealplan.h"

MealPlan::MealPlan()
{

}

MealPlan::MealPlan()
{


}

bool MealPlan::AddMeal(Meal NewMeal)
{
    //checks
    MealList.push_back(NewMeal);
    return true;

}


bool MealPlan::RemoveMeal(Meal TargetMeal)
{
    //think about hasing
    //MealList.Remove(TargetMeal);
    return true;
}


void MealPlan::UpdateNutrition()
{
    TotalCarbs = 0;
    TotalFatContent = 0;
    TotalProtien = 0;
    CalorieCount = 0;

    for(int i = 0; i<MealList.size(); i++)
    {
        //TotalCarbs += MealList[i].MealRecipe.GetTotalCarbs();
        //TotalFatContent += MealList[i].MealRecipe.GetTotalFat();
        //TotalProtien += MealList[i].MealRecipe.GetTotalProtien();
        //CalorieCount += MealList[i].MealRecipe.GetTotalCalories();
    }
    return;
}

void MealPlan::ListMealNames()
{

}

Meal MealPlan::SelectMeal(int index) // maybe the address...or just open up the MealList to public....or the widget
{
    return MealList[index];
}







