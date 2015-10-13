#ifndef MEAL_H
#define MEAL_H


class Meal
{

protected:
    float CalorieCount;
    float TotalProtien;
    Recipe MealRecipe;
    string Date;
    string MealName;

public:
    Meal();
    Meal(string date, Recipe Mealrecipe);

    //bool EditRecipe();
    //maybe the functions below just call the recipe function to add ingrediant or maybe it doesnt have 1 i dunno
    bool AddIngrediant(string ingrediant);  //now this should be in the recipe class I guess
    bool RemoveIngrediant(string ingrediant); //this too
    bool ChangeDate(string newDate);
    bool ChangeName(string newName);
    void ListRecipe(); // display function i guess.....
    //float GetProtien();  in recipe class


signals:





public slots:




};

#endif // MEAL_H
