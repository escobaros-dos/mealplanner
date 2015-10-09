#ifndef RECIPE_H
#define RECIPE_H


class Recipe
{
public:
    Recipe();
    string name;
    vector<string> ingredients;
    string directions;//cooking directions
    vector<string> findIngredients(string recipeName);
    // the find ingredients function will use the select from


signals:

public slots:
};
/*
class Ingredients
{
   string name;
   int protein;
   int calories;


}*/

#endif // RECIPE_H
