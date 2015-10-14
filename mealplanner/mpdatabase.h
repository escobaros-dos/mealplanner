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
    Ingredient &getIngredientByName(String);
    Recipe &getRecipeByName(String);
    std::vector<std::string> &getRecipeNames();
    std::vector<std::string> &getIngredientNames();
    
    //data insertion
    void addRecipeToDatabase(const Recipe &);
    void addIngredientToDatabase(const Ingredient &);

protected:

private:
    QSqlDatabase db;

signals:

public slots:

};

#endif // MPDATABASE_H
