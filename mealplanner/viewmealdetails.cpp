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

    ui->CurrentDateLabel->setText(currentDate);

}

ViewMealDetails::~ViewMealDetails()
{
    delete ui;
}

void ViewMealDetails::updateIngredientTextBrowser()
{

}

void ViewMealDetails::updateRecipeDirecetionTextBrowser()
{

}

void ViewMealDetails::updateMealComboBox()
{

    QList<QString> tempRecipeName = database->getRecipeByDate(currentDate).toList();

    ui->MealsComboBox->addItems(tempRecipeName);


}
