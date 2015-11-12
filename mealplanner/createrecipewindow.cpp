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

    UpdateRecipeList();

}

void CreateRecipeWindow::UpdateRecipeList() // use this same method for the.....meal recipe combo box
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
<<<<<<< HEAD

         ui->listWidget_2->removeItemWidget(i);
         delete i;

=======
         Ingredient In = CurrentIngridients[ui->listWidget_2->currentRow()]; // think.....
         //CurrentIngridients.removeat(ui->listWidget_2->currentRow());
         //CurrentIngridients.removeOne(In);
         ui->listWidget_2->removeItemWidget(i);
         delete i;

        UpdateNutrition(-1, In);
>>>>>>> 1224cbd9ba6b4b17b55f826d7c3b7987e19a65c5
     }

}

void CreateRecipeWindow::on_AddFromDatabase_clicked()
{
    foreach(QListWidgetItem *i, ui->listWidget->selectedItems())
    {
        ui->listWidget_2->addItem(i->text());
        Ingredient In = RecipeDB->getIngredientByName(i->text());
        CurrentIngridients.push_back(In);
        UpdateNutrition(1, In);
    }

}

int prt = 0;
int cal = 0;
int car = 0;
int fat = 0;

void CreateRecipeWindow::UpdateNutrition(int s, Ingredient I)
{

<<<<<<< HEAD
    ui->ProtienInputLabel += I.protein*s;
    ui->CaloriesInputLabel += I.calories*s;
    ui->CarbsInputLabel += I.carbs*s;
    ui->FatInputLabel += I.fat*s;
=======
    prt += I.protein*s;
    cal += I.calories*s;
    car += I.carbs*s;
    fat += I.fat*s;

    ui->ProtienLabel_2->setText(QString::number(prt));
    ui->CalorieLabel_2->setText(QString::number(cal));
    ui->CarbLabel_2->setText(QString::number(car));
    ui->FatLabel_2->setText(QString::number(fat));
>>>>>>> 1224cbd9ba6b4b17b55f826d7c3b7987e19a65c5

}

void CreateRecipeWindow::on_RecipeBackButton_clicked()
{
    this->close();
}
