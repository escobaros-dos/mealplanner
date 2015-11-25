
#include "existingrecipe.h"
#include "ui_existingrecipe.h"


ExistingRecipe::ExistingRecipe(const QString &tempDate, MpDatabase * tempDB, QWidget *parent) :
   QDialog(parent),
   ui(new Ui::ExistingRecipe)
{
   ui->setupUi(this);

   currentDate = tempDate;

   eDatabase = tempDB;

<<<<<<< HEAD
    ui->CurrentDateLabel->setText(currentDate);
    ExistingWinLabels.push_back(ui->ProtienInputLabel);
    ExistingWinLabels.push_back(ui->CaloriesInputLabel);
    ExistingWinLabels.push_back(ui->CarbsInputLabel);
    ExistingWinLabels.push_back(ui->FatInputLabel);
=======
   ExistingWinLabels.push_back(ui->ProtienInputLabel);
   ExistingWinLabels.push_back(ui->CaloriesInputLabel);
   ExistingWinLabels.push_back(ui->CarbsInputLabel);
   ExistingWinLabels.push_back(ui->FatInputLabel);
>>>>>>> 0803ce7d742e06ec862880cebf998d19d105797d

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

<<<<<<< HEAD
    QListIterator<QListWidgetItem*> tempCurrentItemsIterator(ui->listWidget->selectedItems());

    //QListIterator<Recipe> tempRecipeIterator(tempRecipe);

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

    UpdateStatus(ui->ExistingRecipeStatusLabel,CurrentRecipe->getName(), DateAddStatus);
=======
   QListIterator<QListWidgetItem*> tempCurrentItemsIterator(ui->listWidget->selectedItems());
   QList<Recipe> newSelectedRecipe;
   while(tempCurrentItemsIterator.hasNext())
   {
      newSelectedRecipe.append(eDatabase->getRecipeByName(tempCurrentItemsIterator.next()->text()));
   }

   QListIterator<Recipe> newSelectedRecipeIterator(newSelectedRecipe);
>>>>>>> 0803ce7d742e06ec862880cebf998d19d105797d

   while(newSelectedRecipeIterator.hasNext())
   {
      eDatabase->addRecipe(newSelectedRecipeIterator.next(), currentDate);
   }
}

void ExistingRecipe::UpdateMethod()
{

<<<<<<< HEAD
    Value1 = CurrentRecipe->GetProtien();
    Value2 = CurrentRecipe->GetCalories();
    Value3 = CurrentRecipe->GetCarbs();
    Value4 = CurrentRecipe->GetFat();
=======
   prt = CurrentRecipe->GetProtien();
   cal = CurrentRecipe->GetCalories();
   car = CurrentRecipe->GetCarbs();
   fat = CurrentRecipe->GetFat();
>>>>>>> 0803ce7d742e06ec862880cebf998d19d105797d

   return;

}

void ExistingRecipe::on_CloseWindowButton_clicked()
{
   CloseWindow(this);
}

void ExistingRecipe::on_listWidget_clicked(const QModelIndex &index)
{
    // dont need this function any more
   // CurrentRecipe = &tempRecipe.at(index.row());
   // UpdateNutrition(ExistingWinLabels);
}

void ExistingRecipe::on_listWidget_currentRowChanged(int currentRow)
{
   CurrentRecipe = &tempRecipe[currentRow];
   UpdateNutrition(ExistingWinLabels);
}
