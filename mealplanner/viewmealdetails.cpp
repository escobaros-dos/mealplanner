#include "viewmealdetails.h"
#include "ui_viewmealdetails.h"
#include <QDebug>

ViewMealDetails::ViewMealDetails(const QString &currentDate, MpDatabase *db, QWidget *parent) :
   QDialog(parent),
   ui(new Ui::ViewMealDetails)
{
   database = db;
   ui->setupUi(this);

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
<<<<<<< HEAD
    foreach(Ingredient I, R.IngredientsList)
    {
        ui->listOfIngredients->addItem(I.getName());
    }
}

void ViewMealDetails::updateRecipeDirecetionTextBrowser(const QString& RecipeDirections)
{   
    ui->DirectionsTextBrowser->clear();
    ui->DirectionsTextBrowser->setText(RecipeDirections);
=======
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
>>>>>>> 0803ce7d742e06ec862880cebf998d19d105797d
}

void ViewMealDetails::updateRecipeComboBox(const QList<Recipe> &tempRecipeList)
{
<<<<<<< HEAD
    foreach(Recipe r, tempRecipeList)
    {
        ui->MealsComboBox->addItem(r.getName());
    }
=======
   foreach(Recipe r, tempRecipeList)
   {
      ui->MealsComboBox->addItem(r.getName());
   }
>>>>>>> 0803ce7d742e06ec862880cebf998d19d105797d


}

void ViewMealDetails::on_MealsComboBox_activated(const QString &arg1)
{
   // dont need this any more
}

void ViewMealDetails::UpdateMethod()
{
<<<<<<< HEAD
    Value1 = CurrentRecipe->GetProtien();
    Value2 = CurrentRecipe->GetCalories();
    Value3 = CurrentRecipe->GetCarbs();
    Value4 = CurrentRecipe->GetFat();
=======
   prt = CurrentRecipe->GetProtien();
   cal = CurrentRecipe->GetCalories();
   car = CurrentRecipe->GetCarbs();
   fat = CurrentRecipe->GetFat();
>>>>>>> 0803ce7d742e06ec862880cebf998d19d105797d
}

void ViewMealDetails::on_MealsComboBox_activated(int index)
{

<<<<<<< HEAD
    // need to qdebug index values to make sure that vector is in sync with combo box index
    qDebug() << "DISPLAYING: " << recipeList[index].getName();
    qDebug() << "WITH VALUES: " << recipeList[index].GetProtien();
    ui->listOfIngredients->clear();
    ui->DirectionsTextBrowser->clear();
=======
   ui->listOfIngredients->clear();
   ui->DirectionsTextBrowser->clear();
>>>>>>> 0803ce7d742e06ec862880cebf998d19d105797d

   CurrentRecipe = &recipeList[index];
   updateRecipeDirecetionTextBrowser(recipeList[index].GetDirections());

   updateIngredientListWidget(recipeList[index]);

   UpdateNutrition(VMDwinLabels);

}

void ViewMealDetails::on_VMD_Okay_clicked()
{
   CloseWindow(this);
}
