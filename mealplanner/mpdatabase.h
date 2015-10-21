#ifndef MPDATABASE_H
#define MPDATABASE_H

#include <QObject>
#include <QtSql>
#include <QDebug>

#include "meal.h"
#include "recipe.h"
#include "ingredient.h"

class MpDatabase
{

public:
    //constructors
    MpDatabase();
    ~MpDatabase();
    
    /*
     * data retrieval
     */
    //meal functions
    Meal getMealByDate(QString);
    Meal getMealByID(int);

    //ingredient functions
    Ingredient getIngredientByName(QString);
    Ingredient getIngredientByID(int);
    //QVector<QString> getIngredientNames();
    QVector<int> getIngredientIDs();

    //recipe functions
    Recipe getRecipeByName(QString);
    Recipe getRecipeByID(int);
    //QVector<QString> getRecipeNames();
    QVector<int> getRecipeIDs();
    QVector<QString> getRecipesByIngredient(QString &);

    QVector<QString> getNameFromDatabase(const QString &, const QString &);


    /*
     * data insertion
     */
    //meal functions
    void addMeal(const Meal &);

    //ingredient functions
    void addIngredient(const Ingredient &);

    //recipe functions
    void addRecipe(const Recipe &);

    void updateRelationTable(const QString &, const QString &s);




protected:
    int getIngredientIDByName(QString);
    int getRecipeIDByName(QString);

private:
    QSqlDatabase db;

signals:

public slots:

};

#endif // MPDATABASE_H
