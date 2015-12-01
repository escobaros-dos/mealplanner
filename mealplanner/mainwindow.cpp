#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "recipebook.h"
#include "viewmealdetails.h"
#include "createrecipewindow.h"
#include "calcbmi.h"

#include "existingrecipe.h"

MainWindow::MainWindow(MpDatabase* db, QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   MainDB = db;

   currentlySelectedDate = ui->calendarWidget->selectedDate().toString();

   updateMealListWidget();
}

MainWindow::~MainWindow()
{
   delete ui;
}

//-------------------------------------------------------------------
void MainWindow::on_RecipeBookButton_clicked()//opens recipe book
{

   RecipeBook RB;
   RB.setModal(false);
   RB.exec();
   //ui -> stackedWidget -> setCurrentIndex(2);
   //qDebug("index change");//error check


}

void MainWindow::on_ViewDetailsButton_clicked()
{
   ViewMealDetails MealDetailsWindow(currentlySelectedDate, MainDB);
   MealDetailsWindow.setModal(false);
   MealDetailsWindow.exec();
}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{

   //ISSUE: if the user clicks on the same date multiple times the list will keep adding items onto the widget

   currentlySelectedDate = date.toString();

   updateMealListWidget();

   //qDebug() << currentlySelectedDate;
}

//when the user selects a new date the mealListWidget is cleared
void MainWindow::on_calendarWidget_selectionChanged()
{
   ui->listOfMeals->clear();
}



void MainWindow::on_CreateRecipeButton_clicked()
{
   CreateRecipeWindow RecipeWin(currentlySelectedDate, MainDB);
   RecipeWin.setModal(false);
   RecipeWin.exec();

   updateMealListWidget();

}

void MainWindow::updateMealListWidget()
{

   QVector<Recipe> tempRecipeName(MainDB->getRecipeByDate(currentlySelectedDate)); //gets the recipes for the selected date

   ui->listOfMeals->clear(); //clears the list of the old content

   foreach(Recipe r, tempRecipeName)  //foreach of the recipe that was retrieved, it is populated onto the list widget
   {
      ui->listOfMeals->addItem(r.getName());
   }

}

void MainWindow::on_ExistingRecipeButton_clicked()
{
   ExistingRecipe er(currentlySelectedDate, MainDB);
   er.setModal(false);
   er.exec();
   updateMealListWidget();
}

void MainWindow::on_calcBMI_clicked()
{
   CalcBMI bmi;
   bmi.setModal(false);
   bmi.exec();
}
