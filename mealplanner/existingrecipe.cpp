#include "existingrecipe.h"
#include "ui_existingrecipe.h"


ExistingRecipe::ExistingRecipe(const QString &tempDate, MpDatabase * tempDB, QWidget *parent) :
   QDialog(parent),
   ui(new Ui::ExistingRecipe)
{
   ui->setupUi(this);

   currentDate = tempDate;

   eDatabase = tempDB;

   ExistingWinLabels.push_back(ui->ProtienInputLabel);
   ExistingWinLabels.push_back(ui->CaloriesInputLabel);
   ExistingWinLabels.push_back(ui->CarbsInputLabel);
   ExistingWinLabels.push_back(ui->FatInputLabel);

   populateList();
}

ExistingRecipe::~ExistingRecipe()
{
   delete ui;
}

void ExistingRecipe::populateList()
{
   tempRecipe = eDatabase->getAllRecipe();

   QVectorIterator<Recipe>tempRecipeIterator(tempRecipe);

   while(tempRecipeIterator.hasNext())
   {     
      ui->listWidget->addItem(tempRecipeIterator.next().getName());
   }
}

void ExistingRecipe::on_AddRecipeCurrentButton_clicked()
{

   QListIterator<QListWidgetItem*> tempCurrentItemsIterator(ui->listWidget->selectedItems());
   QList<Recipe> newSelectedRecipe;
   while(tempCurrentItemsIterator.hasNext())
   {
      newSelectedRecipe.append(eDatabase->getRecipeByName(tempCurrentItemsIterator.next()->text()));
   }

   QListIterator<Recipe> newSelectedRecipeIterator(newSelectedRecipe);

   while(newSelectedRecipeIterator.hasNext())
   {
      eDatabase->addRecipe(newSelectedRecipeIterator.next(), currentDate);
   }
}

void ExistingRecipe::UpdateMethod()
{

   prt = CurrentRecipe->GetProtien();
   cal = CurrentRecipe->GetCalories();
   car = CurrentRecipe->GetCarbs();
   fat = CurrentRecipe->GetFat();

   return;

}

void ExistingRecipe::on_CloseWindowButton_clicked()
{
   CloseWindow(this);
}

void ExistingRecipe::on_listWidget_clicked(const QModelIndex &index)
{
   // CurrentRecipe = &tempRecipe.at(index.row());
   // UpdateNutrition(ExistingWinLabels);
}

void ExistingRecipe::on_listWidget_currentRowChanged(int currentRow)
{
   CurrentRecipe = &tempRecipe[currentRow];
   UpdateNutrition(ExistingWinLabels);
}
