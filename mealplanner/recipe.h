#ifndef RECIPE_H
#define RECIPE_H

#include <QObject>
#include <QVector>
#include "ingredient.h"


class Recipe
{
public:
    Recipe();
    Recipe(QVector<Ingredient> ingredients, QString steps, QString name, QString date);
    //for custom constructor this will have a date param cuz its going to serve as the meal now...

    QString getName() const;
    QString getDate() const;

    //may need getters and setters?? although this violates encapsulations

    QVector<Ingredient> ingredients; //should this be a vector of Ingredients.
    //QVector<QString> steps; //do we need steps be a vector or could we have this as one long string?
    QString rname;
    QString catSteps; //concatenated string for the
    QString Date;

    int CalorieCount;
    int TotalProtien;
    int TotalCarbs;
    int TotalFatContent;

    int Proportions;

    //for editing an existing recipe

    bool AddIngrediant(Ingredient);
    bool RemoveIngrediant(int index);
    void ChangeDate(QString newDate);
    void ChangeName(QString newName);


    // for viewing
    QString GetDirections();

    int GetCarbs();
    int GetFat();
    int GetProtien();
    int GetCalories();



private:


    void UpdateNutrition();

//signals:





public slots:





};

#endif // RECIPE_H
