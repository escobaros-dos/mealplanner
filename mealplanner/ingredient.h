#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <QObject>
#include <QString>

class Ingredient
{
public:
    Ingredient();
    Ingredient(int protn, int ft, int crbs, int cals, QString n);

    QString getName() const;
    int getProtein() const;
    int getFat() const;
    int getCarbs() const;
    int getCalories() const;


protected:

    QString name;
    int protein;
    int fat;
    int carbs;
    int calories;


};

#endif // INGREDIENT_H
