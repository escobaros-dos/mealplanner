#ifndef MEALPLAN_H
#define MEALPLAN_H

#include <meal.h>
#include <QObject>
#include <Qvector>

class MealPlan : public Meal
{
protected:
    QVector<Meal> MealList; //hash map might be better....
    QVector<QString> WeekRange; //or date range w/e

public:
    MealPlan();
    MealPlan(QVector<string>& dates,QVector<Meal>& meals);

    bool AddMeal(Meal NewMeal); // add a new meal to the meal plan, NOTE: this may increase/extend the range of dates

    //is there a better way of doing this
    bool RemoveMeal(Meal TargetMeal); // remove meal based on the actual meal
    bool RemoveMeal(QString TargetDate); // remove meal based on the date of the meal

    float GetTotalCalories(); // or just nutrients w/e

    void ViewMealPlan(); // rae's idea of week based viewing

    Meal SelectMeal(int index);// just returns the meal at the specified location....hash map might be better

    //the above function is usefull....for editing in the meal plan widget




signals:




public slots:




};

#endif // MEALPLAN_H
