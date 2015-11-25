#include "recipe.h"

Recipe::Recipe()
{
<<<<<<< HEAD
    RecipeName = " ";
    CalorieCount = 0;
    TotalCarbs = 0;
    TotalFatContent = 0;
    TotalProtien = 0;
=======
   rname = " ";
   CalorieCount = 0;
   TotalCarbs = 0;
   TotalFatContent = 0;
   TotalProtien = 0;
>>>>>>> 0803ce7d742e06ec862880cebf998d19d105797d
}

Recipe::Recipe(QVector<Ingredient> ings, QString step, QString name)
{
<<<<<<< HEAD
    IngredientsList = ings;
    DirectionsText = step;
    RecipeName = name;
=======
   ingredients = ings;
   catSteps = step;
   rname = name;
>>>>>>> 0803ce7d742e06ec862880cebf998d19d105797d

   CalorieCount = 0;
   TotalCarbs = 0;
   TotalFatContent = 0;
   TotalProtien = 0;


   CalculateNutrition();

}

QString Recipe::getName() const
{
<<<<<<< HEAD
    return RecipeName;
=======
   return rname;
>>>>>>> 0803ce7d742e06ec862880cebf998d19d105797d
}

void Recipe::CalculateNutrition()
{

<<<<<<< HEAD
    foreach(Ingredient I, IngredientsList.toList())
    {
        CalorieCount += I.getCalories();
        TotalCarbs += I.getCarbs();
        TotalFatContent += I.getFat();
        TotalProtien += I.getProtein();
    }
    return;
=======
   foreach(Ingredient I, ingredients.toList())
   {
      CalorieCount += I.calories;
      TotalCarbs += I.carbs;
      TotalFatContent += I.fat;
      TotalProtien += I.protein;
   }
   return;
>>>>>>> 0803ce7d742e06ec862880cebf998d19d105797d
}


void Recipe::ChangeName(QString newName)
{
<<<<<<< HEAD
    RecipeName = newName;
    return;
=======
   rname = newName;
   return;
>>>>>>> 0803ce7d742e06ec862880cebf998d19d105797d
}

bool Recipe::AddIngrediant(Ingredient NewIngrediant)
{
<<<<<<< HEAD
    //might want to add a check if already in the list, no duplicate ings???
    IngredientsList.push_back(NewIngrediant);
    return true;
}
bool Recipe::RemoveIngrediant(int index) // this function might only need an index param
{
    if(index > IngredientsList.size()) return false;

    IngredientsList.removeAt(index);
    return true;
=======
   ingredients.push_back(NewIngrediant);
   return true;
}
bool Recipe::RemoveIngrediant(int index) // this function might only need an index param
{
   if(index > ingredients.size()) return false;

   ingredients.removeAt(index);
   return true;
>>>>>>> 0803ce7d742e06ec862880cebf998d19d105797d
}

QString Recipe::GetDirections() const
{
<<<<<<< HEAD
    return DirectionsText;
=======
   return catSteps;
>>>>>>> 0803ce7d742e06ec862880cebf998d19d105797d
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
