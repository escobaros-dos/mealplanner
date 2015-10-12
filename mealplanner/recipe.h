#ifndef RECIPE_H
#define RECIPE_H


class Recipe
{
public:
           Recipe();
    String serializeIngredients();
    void   deSerializeIngredients(String);
    String serializeSteps();
    void   deSerializeSteps(String);


private:
    QVector<String> ingredients;
    QVector<String> steps;
    float calories;
    float protein;
    String date;

signals:

public slots:
};

#endif // RECIPE_H
