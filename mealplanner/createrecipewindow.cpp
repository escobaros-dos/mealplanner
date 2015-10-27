#include "createrecipewindow.h"
#include "ui_createrecipewindow.h"

CreateRecipeWindow::CreateRecipeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateRecipeWindow)
{
    ui->setupUi(this);
}

CreateRecipeWindow::~CreateRecipeWindow()
{
    delete ui;
}
