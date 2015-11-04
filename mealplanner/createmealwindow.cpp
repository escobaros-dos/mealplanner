#include "createmealwindow.h"
#include "ui_createmealwindow.h"
#include "createrecipewindow.h"

CreateMealWindow::CreateMealWindow(MpDatabase* db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateMealWindow)
{
    ui->setupUi(this);
    MealWinDB = db;


    QVector<QString> RecNames = MealWinDB->getRecipeNames();

    ui->SelectRecipeComboBox->addItems(RecNames.toList()); // prolly works, but no recipes so can't test

    ui->SelectRecipeComboBox->addItem("hi");
    ui->SelectRecipeComboBox->addItem("hi1");
    ui->SelectRecipeComboBox->addItem("hi2");



}

CreateMealWindow::~CreateMealWindow()
{
    delete ui;
}

void CreateMealWindow::on_CreateRecipeButton_clicked()
{
    CreateRecipeWindow RecipeWin(MealWinDB);
    RecipeWin.setModal(false);
    RecipeWin.exec();

}





void CreateMealWindow::on_MealBackButton_clicked()
{
    this->close();
}


void CreateMealWindow::on_SelectRecipeComboBox_activated(const QString &arg1)
{
    //Recipe R = MealWinDB->getRecipeByName(arg1);

    //for(int i = 0; i,R.ingredients.size(); ++i)
    //{
    //    ui->IngList->addItems(R.ingredients[i].name);
    //}
}
