
#include "existingrecipe.h"
#include "ui_existingrecipe.h"


ExistingRecipe::ExistingRecipe(const QString &tempDate, MpDatabase * tempDB, QWidget *parent) :
   QDialog(parent),
   ui(new Ui::ExistingRecipe)
{
   ui->setupUi(this);

   currentDate = tempDate;

   eDatabase = tempDB;

    ui->CurrentDateLabel->setText(currentDate);

    ExistingWinLabels.push_back(ui->ProtienInputLabel);
    ExistingWinLabels.push_back(ui->CaloriesInputLabel);
    ExistingWinLabels.push_back(ui->CarbsInputLabel);
    ExistingWinLabels.push_back(ui->FatInputLabel);

   populateList(); //gets called to populate the list
}

ExistingRecipe::~ExistingRecipe()
{
   delete ui;
}

void ExistingRecipe::populateList()
{
   tempRecipe = eDatabase->getAllRecipe(); //retrieves all the recipe on the database

   QVectorIterator<Recipe>tempRecipeIterator(tempRecipe); //vector iterator

   while(tempRecipeIterator.hasNext()) //iterates through the vector and populates the list widget
   {     
      ui->listWidget->addItem(tempRecipeIterator.next().getName());
   }
}

void ExistingRecipe::on_AddRecipeCurrentButton_clicked()
{
    //stores the currently selected items on the widget into a list

    QListIterator<QListWidgetItem*> tempCurrentItemsIterator(ui->listWidget->selectedItems());

    QList<Recipe> newSelectedRecipe;

    while(tempCurrentItemsIterator.hasNext()) //iterate through the list and grabs the recipe from the database
    {
        newSelectedRecipe.append(eDatabase->getRecipeByName(tempCurrentItemsIterator.next()->text()));
    }

    QListIterator<Recipe> newSelectedRecipeIterator(newSelectedRecipe);

    while(newSelectedRecipeIterator.hasNext()) //interates through the selected recipes and adds them into the database
    {
        eDatabase->addRecipe(newSelectedRecipeIterator.next(), currentDate);
    }

    UpdateStatus(ui->ExistingRecipeStatusLabel,CurrentRecipe->getName(), DateAddStatus); //prints the status of add

}

void ExistingRecipe::UpdateMethod()
{
    Value1 = CurrentRecipe->GetProtien();
    Value2 = CurrentRecipe->GetCalories();
    Value3 = CurrentRecipe->GetCarbs();
    Value4 = CurrentRecipe->GetFat();

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
