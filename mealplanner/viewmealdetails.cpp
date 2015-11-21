#include "viewmealdetails.h"
#include "ui_viewmealdetails.h"
#include <QDebug>

ViewMealDetails::ViewMealDetails(const QString &currentDate, MpDatabase *db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewMealDetails)
{
    database = db;
    ui->setupUi(this);

    qDebug() << currentDate;

    currentlySelectedDate = currentDate;

    recipeList = database->getRecipeByDate(currentDate).toList();

    updateRecipeComboBox(recipeList);

    ui->CurrentDateLabel->setText(currentDate);

    VMDwinLabels.push_back(ui->ProtienInputLabel);
    VMDwinLabels.push_back(ui->CaloriesInputLabel);
    VMDwinLabels.push_back(ui->CarbsInputLabel);
    VMDwinLabels.push_back(ui->FatInputLabel);
}

ViewMealDetails::~ViewMealDetails()
{
    delete ui;
}

void ViewMealDetails::updateIngredientListWidget(const Recipe& R)
{
    foreach(Ingredient I, R.ingredients)
    {
        ui->listOfIngredients->addItem(I.getName());
    }
}

void ViewMealDetails::updateRecipeDirecetionTextBrowser(const QString& RecipeDirections)
{
    qDebug() << "directions:::" << RecipeDirections;
    ui->DirectionsTextBrowser->clear();
    ui->DirectionsTextBrowser->setText(RecipeDirections);
    //ui->DirectionsTextBrowser->setText("need to work on recipe");
}

void ViewMealDetails::updateRecipeComboBox(const QList<Recipe> &tempRecipeList)
{
    //bug is here too...
    foreach(Recipe r, tempRecipeList)
    {
        qDebug() << "IN UPDATE R COMBO, ADDING: " << r.getName();
        ui->MealsComboBox->addItem(r.getName());
    }


}

void ViewMealDetails::on_MealsComboBox_activated(const QString &arg1)
{
    // dont need this any more
}

void ViewMealDetails::UpdateMethod()
{
    prt = CurrentRecipe->GetProtien();
    cal = CurrentRecipe->GetCalories();
    car = CurrentRecipe->GetCarbs();
    fat = CurrentRecipe->GetFat();
}

void ViewMealDetails::on_MealsComboBox_activated(int index)
{

    // need to qdebug index values to make sure that vector is in sync with combo box index
    //BUG, the index's DON'T synce up properly......gota debug n shit
    qDebug() << "DISPLAYING: " << recipeList[index].getName();
    qDebug() << "WITH VALUES: " << recipeList[index].GetProtien();
    ui->listOfIngredients->clear();
    ui->DirectionsTextBrowser->clear();

    CurrentRecipe = &recipeList[index];
    updateRecipeDirecetionTextBrowser(recipeList[index].GetDirections());

    updateIngredientListWidget(recipeList[index]);

    UpdateNutrition(VMDwinLabels);

}

void ViewMealDetails::on_VMD_Okay_clicked()
{
    CloseWindow(this);
}
