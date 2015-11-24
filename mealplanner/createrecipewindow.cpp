#include "createrecipewindow.h"
#include "ui_createrecipewindow.h"
#include "createingridientwindow.h"
#include <QDebug>
#include <QTextCursor>

CreateRecipeWindow::CreateRecipeWindow(QString& date, MpDatabase* db, QWidget *parent) :
   QDialog(parent),
   ui(new Ui::CreateRecipeWindow)
{
   ui->setupUi(this);
   RecipeDB = db;

   currentDate = date;

   ui->DateLabel->setText(currentDate);

   qDebug() << date;

   RWinLabels.push_back(ui->ProtienInputLabel);
   RWinLabels.push_back(ui->CaloriesInputLabel);
   RWinLabels.push_back(ui->CarbsInputLabel);
   RWinLabels.push_back(ui->FatInputLabel);

   UpdateRecipeList();
}

void CreateRecipeWindow::UpdateRecipeList()
{
   QVector<QString> names = RecipeDB->getIngredientNames();
   ui->listWidget->clear();
   ui->listWidget->addItems(names.toList());
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

   UpdateRecipeList();
}

void CreateRecipeWindow::on_RecipeSaveToDbButton_clicked()
{
   QVector<QString> RecipeSteps;
   QString steps;

   steps = ui->StepsEdit->toPlainText();

   QString RecipeName = ui->RecipeNameEdit->text();

   Recipe NewRecipe(CurrentIngridients, steps, RecipeName);

   //BUG
   //NewRecipe.SetTotalNutrition(prt, cal, car, fat);


   qDebug() << "ADDING RECIPE WITH VALUES: " << NewRecipe.GetProtien();
   RecipeDB->addRecipe(NewRecipe, currentDate);


   SetLabels(RWinLabels, 0);
   ui->RecipeNameEdit->clear();
   RecipeSteps.clear();
   CurrentIngridients.clear();
   ui->listWidget_2->clear();
   ui->StepsEdit->clear();
   //*****

   UpdateStatus(ui->RecipeStatusLabel, NewRecipe.getName());

}

void CreateRecipeWindow::on_RemoveFromSelected_clicked()
{
   foreach(QListWidgetItem *i, ui->listWidget_2->selectedItems())
   {
      Ingredient In = CurrentIngridients[ui->listWidget_2->currentRow()]; // think.....
      CurrentIngridients.removeAt(ui->listWidget_2->currentRow());
      ui->listWidget_2->removeItemWidget(i);
      delete i;
      //UpdateNutrition(-1, In);

      UpdateSign = -1;
      ChangedIngredient = &In;
      UpdateNutrition(RWinLabels);
   }
}

void CreateRecipeWindow::on_AddFromDatabase_clicked()
{
   foreach(QListWidgetItem *i, ui->listWidget->selectedItems())
   {
      ui->listWidget_2->addItem(i->text());
      Ingredient In = RecipeDB->getIngredientByName(i->text());
      CurrentIngridients.push_back(In);
      //UpdateNutrition(1, In);

      UpdateSign = 1;
      ChangedIngredient = &In;
      UpdateNutrition(RWinLabels);
   }
}

void CreateRecipeWindow::UpdateMethod()
{

   prt += ChangedIngredient->getProtein()*UpdateSign;
   cal += ChangedIngredient->getCalories()*UpdateSign;
   car += ChangedIngredient->getCarbs()*UpdateSign;
   fat += ChangedIngredient->getFat()*UpdateSign;

}

void CreateRecipeWindow::on_RecipeBackButton_clicked()
{
   CloseWindow(this);
}
