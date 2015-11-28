#include "viewmealdetails.h"
#include "ui_viewmealdetails.h"
#include <QDebug>

ViewMealDetails::ViewMealDetails(const QString &currentDate, MpDatabase *db, QWidget *parent) :
   QDialog(parent),
   ui(new Ui::ViewMealDetails)
{
   database = db;
   ui->setupUi(this);

   currentlySelectedDate = currentDate; //stores the currently selected date

   recipeList = database->getRecipeByDate(currentDate).toList(); //grabs all the recipes for the selected date

   updateRecipeComboBox(recipeList); //gets called update the recipe combo box

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
    //populates the list widget with the list of ingredient for the selected recipe

    foreach(Ingredient I, R.IngredientsList)
    {
        ui->listOfIngredients->addItem(I.getName());
    }
}

void ViewMealDetails::updateRecipeDirecetionTextBrowser(const QString& RecipeDirections)
{   
    //clears the text field of the old content and updates with the new content

    ui->DirectionsTextBrowser->clear();

    ui->DirectionsTextBrowser->setText(RecipeDirections);
}

void ViewMealDetails::updateRecipeComboBox(const QList<Recipe> &tempRecipeList)
{
    //populates the combo box with the names of the recipe

    foreach(Recipe r, tempRecipeList)
    {
        ui->MealsComboBox->addItem(r.getName());
    }
}

void ViewMealDetails::on_MealsComboBox_activated(const QString &arg1)
{
   // dont need this any more
}

void ViewMealDetails::UpdateMethod()
{
    //updates the total nutritional values for that recipe

    Value1 = CurrentRecipe->GetProtien();
    Value2 = CurrentRecipe->GetCalories();
    Value3 = CurrentRecipe->GetCarbs();
    Value4 = CurrentRecipe->GetFat();
}

void ViewMealDetails::on_MealsComboBox_activated(int index)
{

   qDebug() << "DISPLAYING: " << recipeList[index].getName();
   qDebug() << "WITH VALUES: " << recipeList[index].GetProtien();

   ui->listOfIngredients->clear();

   ui->DirectionsTextBrowser->clear();

   CurrentRecipe = &recipeList[index]; //currently selected recipe from the combo box

   updateRecipeDirecetionTextBrowser(recipeList[index].GetDirections()); //calls to update the directions or instructions of the recipe

   updateIngredientListWidget(recipeList[index]); //calls to update the ingredient in the list widget

   UpdateNutrition(VMDwinLabels);

}

void ViewMealDetails::on_VMD_Okay_clicked()
{
   CloseWindow(this);
}
