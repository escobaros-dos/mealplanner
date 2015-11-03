#include "createrecipewindow.h"
#include "ui_createrecipewindow.h"
#include "createingridientwindow.h"

CreateRecipeWindow::CreateRecipeWindow(MpDatabase* db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateRecipeWindow)
{
    ui->setupUi(this);
    RecipeDB = db;
}

CreateRecipeWindow::~CreateRecipeWindow()
{
    delete ui;
}

void CreateRecipeWindow::on_CreateIngridientButton_clicked()
{
    CreateIngridientWindow IngridientWin(RecipeDB);
    IngridientWin.setModal(false);
    IngridientWin.exec();
}
