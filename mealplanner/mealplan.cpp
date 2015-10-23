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
    MealList.Add(NewMeal);
    return true;

}


bool MealPlan::RemoveMeal(Meal TargetMeal)
{
    MealList.Remove(TargetMeal);
    return true;
}

bool MealPlan::RemoveMeal(string TargetDate)
{
    MealList.Remove(TargetDate);
    return true;
}

float MealPlan::GetTotalCalories()
{
    float Total;
    for(int i = 0; i<MealList.Size(); i++)
    {
        Total += MealList[i].CalorieCount;
    }
    return Total;
}

void MealPlan::ViewMealPlan()
{
    for(int i = 0; i<MealList.Size(); i++)
    {
        MealList[i].MealRecipe.Display(); //retruns a string or something for the combo box/ widget field w/e
    }
    return;
}

Meal MealPlan::SelectMeal(int index) // maybe the address...or just open up the MealList to public....or the widget
{
    return MealList[index];
}







