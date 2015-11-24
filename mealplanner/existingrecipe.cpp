#include "existingrecipe.h"
#include "ui_existingrecipe.h"


ExistingRecipe::ExistingRecipe(const QString &tempDate, MpDatabase * tempDB, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExistingRecipe)
{
    ui->setupUi(this);

    currentDate = tempDate;

    eDatabase = tempDB;

    populateList();
}

ExistingRecipe::~ExistingRecipe()
{
    delete ui;
}

void ExistingRecipe::populateList()
{
    QList<Recipe> tempRecipe = eDatabase->getAllRecipe().toList();

    QListIterator<Recipe> tempRecipeIterator(tempRecipe);

    //QList<QString> tempName;

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
        //qDebug() << newSelectedRecipeIterator.next().getName();
        eDatabase->addRecipe(newSelectedRecipeIterator.next(), currentDate);
    }

    // qDebug() << "add clicked";

}

void ExistingRecipe::UpdateMethod()
{

}


void ExistingRecipe::on_CloseWindowButton_clicked()
{
    CloseWindow(this);
}

void ExistingRecipe::on_listWidget_clicked(const QModelIndex &index)
{

}
