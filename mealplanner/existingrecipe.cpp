
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
        //tempName.append(tempRecipeIterator.next().getName());
        ui->listWidget->addItem(tempRecipeIterator.next().getName());
    }

    //ui->listWidget->addItems(tempName);

}

void ExistingRecipe::on_AddRecipeCurrentButton_clicked()
{

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
