#ifndef MEAL_H
#define MEAL_H

#include <QObject>
#include "recipe.h"

class Meal
{

protected:


    //think about psudo hashing a vector with enums....
    enum Nutriant
    {
        Protien,  // 0
        Carbs, // 1
        Calorie, // 2
        Fat, // 3
    };

    // probably not protected in final
    float CalorieCount;
    float TotalProtien;
    float TotalCarbs;
    float TotalFatContent;

    float SumUp(Nutriant n);

    int Proportions;

    Recipe MealRecipe;
    QString Date;
    QString MealName;

    float GetCarbs();
    float GetFat();
    float GetProtien();

public:
    Meal();
    Meal(QString name,QString date, int proportion, Recipe Mealrecipe);

    //bool EditRecipe();
    //maybe the functions below just call the recipe function to add ingrediant or maybe it doesnt have 1 i dunno
    bool AddIngrediant(QString ingrediant);  //now this should be in the recipe class I guess
    bool RemoveIngrediant(QString ingrediant); //this too
    bool ChangeDate(QString newDate);
    bool ChangeName(QString newName);
    void ListRecipe(); // display function i guess.....returns the QString or w/e, can change later
    //float GetProtien();  in recipe class

    virtual void UpdateNutrition();

    float GetNutrients(Nutriant n);


//signals:



public slots:



};

#endif // MEAL_H
