#ifndef MEAL_H
#define MEAL_H

#include <QObject>
#include "recipe.h"

class Meal
{

protected:

    //think about psudo hashing a vector with enums....


    // probably not protected in final
    int CalorieCount;
    int TotalProtien;
    int TotalCarbs;
    int TotalFatContent;

    int Proportions;

    Recipe MealRecipe;
    QString Date;
    QString MealName;

    int GetMealCarbs();
    int GetMealFat();
    int GetMealProtien();
    int GetMealCalories();

    virtual void UpdateNutrition();

public:
    Meal();
    Meal(QString date, int proportion, Recipe Mealrecipe);


    enum Nutriant
    {
        Protien,  // 0
        Carbs, // 1
        Calorie, // 2
        Fat, // 3
    };


    //bool EditRecipe();
    //maybe the functions below just call the recipe function to add ingrediant or maybe it doesnt have 1 i dunno
    bool AddIngrediant(QString ingrediant);  //now this should be in the recipe class I guess
    bool RemoveIngrediant(QString ingrediant); //this too
    void ChangeDate(QString newDate);
    void ChangeName(QString newName);
    QVector<QString>& ListRecipe(); // display function i guess.....returns the QString or w/e, can change later


    int GetNutrients(Nutriant n);





//signals:



public slots:



};

#endif // MEAL_H
