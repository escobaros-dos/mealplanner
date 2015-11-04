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

void CreateIngridientWindow::on_SaveIngtoDbButton_clicked()
{
    QString Name = ui->lineEdit->text();
    int protein = ui->protienEdit->text().toInt();
    int calories = ui->CalorieEdit->text().toInt();
    int carbs = ui->CarbEdit->text().toInt();
    int fat = ui->FatEdit->text().toInt();


   // Ingredient(int protn, int ft, int crbs, int cals, QString n);
    Ingredient NewIngredient(protein, fat, carbs, calories, Name);

    IngredientWinDB->addIngredient(NewIngredient); // returns a bool maybe?

    // sooo, at the moment empty text fields will be added to the database...probably not good, fix that later
    ui->lineEdit->clear();
    ui->protienEdit->clear();
    ui->CalorieEdit->clear();
    ui->CarbEdit->clear();
    ui->FatEdit->clear();

    ui->AddIngStatus->setText(NewIngredient.name + " was succesfully added to the database.");

    //NOTE: IF YOU ADD AN IGREDIENT AND THEN HIT THE BACK BUTTON TO CLOSE THE WINDOW, THE PREVIOUS WINDOW
    // WILL BE THE CREATE RECIPE WINDOW AND ITS LIST OF INGREDIENTS IN THE DATABASE WILL NOT BE OUT OF DATE
    //NEED TO UPDATE THAT IN THE BACK BUTTON FUCNTION BELOW -CJ

   // qDebug() << "return from db call\n";

}

void CreateIngridientWindow::on_IngBackButton_clicked()
{
    this->close();
    // need to update the recipe window widget when this is clicked, should be easy, maybe pass that widget in
    // as a pointer and update it here, call a function or w/e. pull out the constructor code to a function...ye do that
}
