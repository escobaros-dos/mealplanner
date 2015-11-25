#include "ingredient.h"
#include <QDebug>

Ingredient::Ingredient()
{
<<<<<<< HEAD
    name="FOOBAR";
    calories = 0;
    carbs = 0;
    fat = 0;
    protein = 0;
=======
   name="FOOBAR";
>>>>>>> 0803ce7d742e06ec862880cebf998d19d105797d
}

Ingredient::Ingredient(int protn, int ft, int crbs, int cals, QString n)
{
   name = n;
   calories = cals;
   carbs = crbs;
   fat = ft;
   protein = protn;
}


QString Ingredient::getName() const
{
   return name;
}

int Ingredient::getCalories() const
{
   return calories;
}

int Ingredient::getCarbs() const {
   return carbs;
}

int Ingredient::getFat() const
{
   return fat;
}

int Ingredient::getProtein() const
{
   return protein;
}
