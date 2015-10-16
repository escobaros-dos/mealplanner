#ifndef RECIPE_H
#define RECIPE_H

#include <QObject>
#include <QVector>
#include <string>

class Recipe
{
public:
           Recipe();
    QString serializeIngredients();
    void   deSerializeIngredients(QString);
    QString serializeSteps();
    void   deSerializeSteps(QString);

    //may need getters and setters?? although this violates encapsulations

private:
    QVector<QString> ingredients;
    QVector<QString> steps; //do we need steps be a vector or could we have this as one long string?
    QString name;
    QString catSteps; //concatenated string for the


signals:

public slots:
};

#endif // RECIPE_H
