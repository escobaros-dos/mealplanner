#include "recipe.h"

Recipe::Recipe()
{
    name = " ";
    Date = " ";
    CalorieCount = 0;
    TotalCarbs = 0;
    TotalFatContent = 0;
    TotalProtien = 0;
    Proportions = 0;
}

void Recipe::UpdateNutrition() // WANT THIS AS AN INTERFACE OR MAIN WINDOW INHERITED FUNCTION....BAD DESIGN
{

    //same as in create recipe windowwwwwwwowowowowowo

    //int s and ingredient I as params

    //CalorieCount += I.calories*s
    //TotalCarbs +=
    //TotalFatContent +=
    //TotalProtien +=

}

Recipe::Recipe(QVector<Ingredient> ings, QString step, QString name, QString date)
{
    ingredients=ings;
    catSteps = step;
    name=name;
    Date = date;



    // this code probably is not neccesary becuase of the create recipe window its already calculated
    // depends on if I want to add a vector of ints as a param to the recipe constructor

    foreach(Ingredient I, ingredients.toList())
    {
        CalorieCount += I.calories;
        TotalCarbs += I.carbs;
        TotalFatContent += I.fat;
        TotalProtien += I.protein;
    }

    //UpdateNutrition();

}

QString Recipe::getName() const
{
    return name;
}

QString Recipe::getDate() const
{
    return Date;
}

void Recipe::ChangeDate(QString newDate)
{
    Date = newDate;
    return;
}

void Recipe::ChangeName(QString newName) // maybe change these names to update names
{
    name = newName;
    return;
}

bool Recipe::AddIngrediant(Ingredient NewIngrediant) // QString or class?
{
    //might want to add a check if already in the list, no duplicate ings???
    ingredients.push_back(NewIngrediant);
    UpdateNutrition();
    return true;
}
bool Recipe::RemoveIngrediant(int index) // this function might only need an index param
{
    if(index > ingredients.size()) return false;

    ingredients.removeAt(index);
    UpdateNutrition();
    return true;

}

//for viewing
int Recipe::GetCalories()
{
    return CalorieCount*Proportions;
}
int Recipe::GetProtien()
{
    return TotalProtien*Proportions;
}
int Recipe::GetFat()
{
    return TotalFatContent*Proportions;
}
int Recipe::GetCarbs()
{
    return TotalCarbs*Proportions;
}
