#ifndef MPDATABASE_H
#define MPDATABASE_H

#include <QObject>
#include <QtSql>
#include <QDebug>
#include <QVectorIterator>

#include "meal.h"
#include "recipe.h"
#include "ingredient.h"


class MpDatabase
{

public:

   static MpDatabase& GetDBInstance(); // returns an instance of the singleton



    /*
     * data retrieval
     */
    //meal functions
    Meal getMealByDate(const QString &);

    Meal getMealByID(int);

    //ingredient functions
    Ingredient getIngredientByName(const QString &);

    Ingredient getIngredientByID(int);

    QVector<QString> getIngredientNames();

    //recipe functions
    Recipe getRecipeByName(const QString &);

    Recipe getRecipeByID(int);

    QVector<Recipe> getRecipeByDate(const QString &); //gets the recipe by date



    QVector<Recipe> getAllRecipe();

    //QVector<QString> getNameFromDatabase(const QString &, const QString &);


    /*
     * data insertion
     */

    //meal functions
    void addMeal(const QString &);

    //ingredient functions
    void addIngredient(const Ingredient &);

    //recipe functions
    void addRecipe(const Recipe &, const QString);

protected:
    int getIngredientIDByName(const QString &);
    int getRecipeIDByName(const QString &);
    int getMealIDByDate(const QString &);

private:
    //singleton
    MpDatabase();
    MpDatabase(MpDatabase const&); // dont implement
    void operator = (MpDatabase const&); // dont implement

    void updateRecipeIngredientRelation(const QString &, const QString &s);

    void updateMealRecipeRelation(const QString &, const QString &);

    QVector<QString> getRecipeNames();

    QVector<int> getRecipeIDs();

    QVector<QString> getRecipesByIngredient(const QString &);

    QVector<QString> getIngredientsByRecipe(const QString &);

    QVector<int> getIngredientIDs();


    QSqlDatabase db;
    QSqlQuery q; //in the constructor assign the database to this

//signals:

public slots:

};

#endif // MPDATABASE_H
