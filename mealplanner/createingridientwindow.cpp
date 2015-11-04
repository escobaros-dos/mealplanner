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

void CreateIngridientWindow::on_lineEdit_textEdited(const QString &arg1)
{
   // NewIngredient.name = arg1;
}

void CreateIngridientWindow::on_protienEdit_textEdited(const QString &arg1)
{
   // NewIngredient.protein = arg1.toInt();
}

void CreateIngridientWindow::on_CalorieEdit_textEdited(const QString &arg1)
{
   // NewIngredient.calories = arg1.toInt();
}

void CreateIngridientWindow::on_CarbEdit_textEdited(const QString &arg1)
{
   // NewIngredient.carbs = arg1.toInt();
}

void CreateIngridientWindow::on_FatEdit_textEdited(const QString &arg1)
{
   // NewIngredient.fat = arg1.toInt();
}

void CreateIngridientWindow::on_buttonBox_accepted()
{

    NewIngredient.name = ui->lineEdit->text();
    NewIngredient.protein = ui->protienEdit->text().toInt();
    NewIngredient.calories = ui->CalorieEdit->text().toInt();
    NewIngredient.carbs = ui->CarbEdit->text().toInt();
    NewIngredient.fat = ui->FatEdit->text().toInt();
    NewIngredient.id = 0;


    IngredientWinDB->addIngredient(NewIngredient);

    qDebug() << "return from db call\n";
}



void CreateIngridientWindow::on_pushButton_clicked()
{
    NewIngredient.name = ui->lineEdit->text();
    NewIngredient.protein = ui->protienEdit->text().toInt();
    NewIngredient.calories = ui->CalorieEdit->text().toInt();
    NewIngredient.carbs = ui->CarbEdit->text().toInt();
    NewIngredient.fat = ui->FatEdit->text().toInt();
    NewIngredient.id = 0;


    IngredientWinDB->addIngredient(NewIngredient);

    qDebug() << "return from db call\n";
}
