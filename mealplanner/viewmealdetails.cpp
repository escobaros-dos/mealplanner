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

    recipeName = database->getRecipeByDate(currentDate).toList();

    updateMealComboBox(recipeName);

    ui->CurrentDateLabel->setText(currentDate);

}

ViewMealDetails::~ViewMealDetails()
{
    delete ui;
}

void ViewMealDetails::updateIngredientListWidget(const QString &tempRecipeName)
{
    QList<QString> tempIngredientList = database->getIngredientsByRecipe(tempRecipeName).toList();

    ui->listOfIngredients->addItems(tempIngredientList);
}

void ViewMealDetails::updateRecipeDirecetionTextBrowser(const QString& RecipeDirections)
{
    qDebug() << "directions:::" << RecipeDirections;
    ui->DirectionsTextBrowser->clear();
    ui->DirectionsTextBrowser->setText(RecipeDirections);
    //ui->DirectionsTextBrowser->setText("need to work on recipe");
}

void ViewMealDetails::updateMealComboBox(const QList<QString> &tempRecipeList)
{

    ui->MealsComboBox->addItems(tempRecipeList);

}

void ViewMealDetails::on_MealsComboBox_activated(const QString &arg1)
{
    //qDebug() << arg1;

    //ISSUE: when the view detail window is open the ingredients and direction ui are not populated with information    

    ui->listOfIngredients->clear();

    ui->DirectionsTextBrowser->clear();

    ui->DirectionsTextBrowser->setText(database->getRecipeByName(arg1).GetDirections());

    Recipe R = database->getRecipeByName(arg1);
    qDebug() << "rrrrrr" << R.getName();

    //updateRecipeDirecetionTextBrowser(database->getRecipeByName(arg1).GetDirections());

    updateIngredientListWidget(arg1);
}
