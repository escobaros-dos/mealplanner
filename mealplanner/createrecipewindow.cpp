#include "createrecipewindow.h"
#include "ui_createrecipewindow.h"
#include "createingridientwindow.h"
#include <QDebug>

CreateRecipeWindow::CreateRecipeWindow(MpDatabase* db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateRecipeWindow)
{
    ui->setupUi(this);
    RecipeDB = db;

    QVector<QString> names = RecipeDB->getIngredientNames();
    for(int i = 0; i<names.size(); ++i)
    {
        ui->listWidget->addItem(names[i]);
    }

    QVector<Ingredient> Ings;

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


void CreateRecipeWindow::on_RecipeSaveToDbButton_clicked()
{
    QVector<QString> RecipeSteps;

    //for(int i = 0; i<ui->listWidget_2->count(); ++i)
    //{
        //Ingredient In = RecipeDB->getIngredientByName(ui->listWidget_2->item(i)->text());
        //Ingredients.push_back(In);
        //qDebug() << ui->listWidget_2->item(i)->text();
    //}

    QString RecipeName = ui->RecipeNameEdit->text();
    //QString CatSteps = Catstepsfunction();

    //Recipe NewRecipe(CurrentIngredients, RecipeSteps, RecipeName, CatSteps)

    //RecipeDB->addRecipe(NewRecipe);

    RecipeSteps.clear();
    CurrentIngridients.clear();
    ui->listWidget_2->clear();
    ui->StepsEdit->clear();
}

void CreateRecipeWindow::on_RemoveFromSelected_clicked()
{
     foreach(QListWidgetItem *i, ui->listWidget_2->selectedItems())
     {
         //Ingredient In = CurrentIngridients[ui->listWidget_2->currentRow()]; this might not work
         //CurrentIngrideints.removeat(ui->listWidget_2->currentRow());
         ui->listWidget_2->removeItemWidget(i);
         delete i;

        //UpdateNutrition(-1, In);
     }

}

void CreateRecipeWindow::on_AddFromDatabase_clicked()
{
    foreach(QListWidgetItem *i, ui->listWidget->selectedItems())
    {
        ui->listWidget_2->addItem(i->text());
        //Ingredient In = RecipeDB->getIngredientByName(ui->listWidget_2->item(i)->text();
        //CurrentIngredients.push_back(In);
        //UpdateNutrition(1, In);
    }

}

void CreateRecipeWindow::UpdateNutrition(int s, Ingredient& I)
{

    ui->ProtienLabel_2 += I.protein*s;
    ui->CalorieLabel_2 += I.calories*s;
    ui->CarbLabel_2 += I.carbs*s;
    ui->FatLabel_2 += I.fat*s;

}

void CreateRecipeWindow::on_RecipeBackButton_clicked()
{
    this->close();
}
