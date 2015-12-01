#ifndef RECIPE_H
#define RECIPE_H

#include <QObject>
#include <QVector>
#include "ingredient.h"


//Class Purpose:  Provides a basic container to hold and disaply data relevant to a recipe

class Recipe
{
public:
    Recipe();
    Recipe(QVector<Ingredient> IngredientsList, QString steps, QString name);

    QVector<Ingredient> IngredientsList;
    QString RecipeName;
    QString DirectionsText; //concatenated string for the diretions

    //total nutrition values of all the ingredients
    int CalorieCount;
    int TotalProtien;
    int TotalCarbs;
    int TotalFatContent;

    //for editing an existing recipe
    //currently not in use.

    bool AddIngrediant(Ingredient);
    bool RemoveIngrediant(int index);
    void ChangeName(QString newName);


    // for disapying to widgets and providing information for the database
    QString GetDirections() const;
    QString getName() const;
    int GetCarbs();
    int GetFat();
    int GetProtien();
    int GetCalories();


private:

    void CalculateNutrition();
    void UpdateNutrition();

};

#endif // RECIPE_H
