#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <QObject>
#include <QString>

class Ingredient
{
public:
    Ingredient();

    QString getName() const;
    int getProtein() const;
    int getFat() const;
    int getCarbs() const;
    int getCalories() const;

protected:
    QString name;
    int id;
    int protein;
    int fat;
    int carbs;
    int calories;

signals:

public slots:
};

#endif // INGREDIENT_H
