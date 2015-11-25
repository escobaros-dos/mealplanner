#include "createingridientwindow.h"
#include "ui_createingridientwindow.h"

CreateIngridientWindow::CreateIngridientWindow(MpDatabase* db, QWidget *parent) :
   QDialog(parent),
   ui(new Ui::CreateIngridientWindow)
{
   ui->setupUi(this);
   IngredientWinDB = db;
}

CreateIngridientWindow::~CreateIngridientWindow()
{
   delete ui;
}

void CreateIngridientWindow::UpdateMethod()
{
   // no implementation
}

void CreateIngridientWindow::on_SaveIngtoDbButton_clicked()
{
   QString Name = ui->IngNameInput->text();
   int protein = ui->protienEdit->text().toInt();
   int calories = ui->CalorieEdit->text().toInt();
   int carbs = ui->CarbEdit->text().toInt();
   int fat = ui->FatEdit->text().toInt();

   Ingredient NewIngredient(protein, fat, carbs, calories, Name);

   IngredientWinDB->addIngredient(NewIngredient);

   ui->IngNameInput->clear();
   ui->protienEdit->clear();
   ui->CalorieEdit->clear();
   ui->CarbEdit->clear();
   ui->FatEdit->clear();

<<<<<<< HEAD
    UpdateStatus(ui->AddIngStatus, Name, DatabaseStatusMsg);
=======
   UpdateStatus(ui->AddIngStatus, Name);
   //ui->AddIngStatus->setText(NewIngredient.name + " was succesfully added to the database.");

>>>>>>> 0803ce7d742e06ec862880cebf998d19d105797d
}

void CreateIngridientWindow::on_IngBackButton_clicked()
{
   CloseWindow(this);
}
