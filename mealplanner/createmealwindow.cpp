#include "createmealwindow.h"
#include "ui_createmealwindow.h"
#include "createrecipewindow.h"

CreateMealWindow::CreateMealWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateMealWindow)
{
    ui->setupUi(this);
}

CreateMealWindow::~CreateMealWindow()
{
    delete ui;
}

void CreateMealWindow::on_pushButton_clicked()
{

}

void CreateMealWindow::on_CreateRecipeButton_clicked()
{
    CreateRecipeWindow RecipeWin;
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
