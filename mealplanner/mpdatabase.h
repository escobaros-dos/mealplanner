#ifndef MPDATABASE_H
#define MPDATABASE_H

#include <QObject>
#include <QtSql>

#include "recipe.h"
#include "ingredient.h"

class MpDatabase
{

public:
    //constructors
    MpDatabase();
    ~MpDatabase();
    
    //data retrieval
    //adding meal and meal plan???
    Ingredient &getIngredientByName(QString);
    Recipe &getRecipeByName(QString);

    //maybe template the function
    QVector<QString> &getRecipeNames();
    QVector<QString> &getIngredientNames();

    QVector<QString> recipeByIngredient(QString &);
    
    //data insertion
    //maybe create a template out of these two functions

    void addRecipeToDatabase(const Recipe &);
    void addIngredientToDatabase(const Ingredient &);



protected:

private:
    QSqlDatabase db;

signals:

public slots:

};

#endif // MPDATABASE_H
