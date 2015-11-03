#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <QObject>
#include <QString>

class Ingredient
{
public:
    Ingredient();
    Ingredient(int protn, int ft, int crbs, int cals, int id, QString n);

    QString getName() const;
    int getProtein() const;
    int getFat() const;
    int getCarbs() const;
    int getCalories() const;


    QString name;
    int id;
    int protein;
    int fat;
    int carbs;
    int calories;


protected:




signals:



public slots:



};

#endif // INGREDIENT_H
