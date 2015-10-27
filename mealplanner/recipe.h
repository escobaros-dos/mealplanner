#ifndef RECIPE_H
#define RECIPE_H

#include <QObject>
#include <QVector>
#include "ingredient.h"

using namespace std; //<-----lololololo

class Recipe
{
public:
    Recipe();
    Recipe(QVector<Ingredient> ingredients, QVector<QString> steps, QString name, QString catstep);

    QString serializeIngredients();
    void   deSerializeIngredients(QString);
    QString serializeSteps();
    void   deSerializeSteps(QString);

    QString getName() const;

    //may need getters and setters?? although this violates encapsulations

    QVector<Ingredient> ingredients; //should this be a vector of Ingredients.
    QVector<QString> steps; //do we need steps be a vector or could we have this as one long string?
    QString name;
    QString catSteps; //concatenated string for the


private:




//signals:





public slots:





};

#endif // RECIPE_H
