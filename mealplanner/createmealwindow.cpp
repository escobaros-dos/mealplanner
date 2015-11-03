#include "createmealwindow.h"
#include "ui_createmealwindow.h"
#include "createrecipewindow.h"

CreateMealWindow::CreateMealWindow(MpDatabase* db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateMealWindow)
{
    ui->setupUi(this);
    MealWinDB = db;
}

CreateMealWindow::~CreateMealWindow()
{
    delete ui;
}

void CreateMealWindow::on_CreateRecipeButton_clicked()
{
    CreateRecipeWindow RecipeWin(MealWinDB);
   //CreateRecipeWindow RW = CreateRecipeWindow(MealWinDB);
    RecipeWin.setModal(false);
    RecipeWin.exec();

}

void CreateMealWindow::on_buttonBox_accepted()
{
    //send save signal to database manager




}

void CreateMealWindow::on_lineEdit_2_textChanged(const QString &arg1)
{

}
