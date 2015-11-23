#ifndef MPDATABASE_H
#define MPDATABASE_H

#include <QObject>
#include <QtSql>
#include <QDebug>
#include <QVectorIterator>

#include "meal.h"
#include "recipe.h"
#include "ingredient.h"

//NOTE: This might be a really good place for forward class declarations*********
//That way we don't need to include all those .h's


class MpDatabase
{

public:
    //constructors

    static MpDatabase& GetDBInstance();




     //MpDatabase();
    //~MpDatabase();
    
    /*
     * data retrieval
     */
    //meal functions
    Meal getMealByDate(QString);
    Meal getMealByID(int);

    //ingredient functions
    Ingredient getIngredientByName(QString);
    Ingredient getIngredientByID(int);

    QVector<QString> getIngredientNames();
    QVector<int> getIngredientIDs();

    //recipe functions
    Recipe getRecipeByName(QString);
    Recipe getRecipeByID(int);

    QVector<Recipe> getRecipeByDate(const QString &); //gets the recipe by date

    QVector<QString> getRecipeNames();

    QVector<int> getRecipeIDs();

    QVector<QString> getRecipesByIngredient(const QString &);

    QVector<QString> getIngredientsByRecipe(const QString &);

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

    void updateRecipeIngredientRelation(const QString &, const QString &s);

    void updateMealRecipeRelation(const QString &, const QString &);




protected:
    int getIngredientIDByName(const QString &);
    int getRecipeIDByName(const QString &);
    int getMealIDByDate(const QString &);

private:
    //singleton
    MpDatabase();
    MpDatabase(MpDatabase const&); // dont implement
    //void operator = (MpDatabase const&); // dont implement


    QSqlDatabase db;
    QSqlQuery q; //in the constructor assign the database to this

//signals:

public slots:

};

#endif // MPDATABASE_H
