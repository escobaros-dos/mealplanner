#ifndef RECIPE_H
#define RECIPE_H

#include <QObject>
#include <QVector>
#include <string>

class Recipe
{
public:
           Recipe();
    std::string serializeIngredients();
    void   deSerializeIngredients(std::string);
    std::string serializeSteps();
    void   deSerializeSteps(std::string);


private:
    QVector<std::string> ingredients;
    QVector<std::string> steps;
    float calories;
    float protein;
    std::string date;

signals:

public slots:
};

#endif // RECIPE_H
