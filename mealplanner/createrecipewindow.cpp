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
    QVector<Ingredient> Ingredients; // have  current ingredients
    QString steps;

    for(int i = 0; i<ui->listWidget_2->count(); ++i)
    {
        Ingredient In = RecipeDB->getIngredientByName(ui->listWidget_2->item(i)->text());
        Ingredients.append(In);
        qDebug() << ui->listWidget_2->item(i)->text();
    }

    steps = ui->StepsEdit->document()->toPlainText();

    foreach(QString step,steps.split("\n")) {
        RecipeSteps.append(step);
    }

    QString RecipeName = ui->RecipeNameEdit->text();

    qDebug() << "recipe name: " << RecipeName;

    Recipe NewRecipe(Ingredients, steps, RecipeName, currentDate);

    //qDebug() << "....." << NewRecipe.GetDirections();

    RecipeDB->addRecipe(NewRecipe);

    ui->RecipeNameEdit->clear();
    RecipeSteps.clear();
    CurrentIngridients.clear();
    ui->listWidget_2->clear();
    ui->StepsEdit->clear();

    ui->RecipeStatusLabel->setText(NewRecipe.getName() + " was successfuly added to the database");

}

void CreateRecipeWindow::on_RemoveFromSelected_clicked()
{
     foreach(QListWidgetItem *i, ui->listWidget_2->selectedItems())
     {

         Ingredient In = CurrentIngridients[ui->listWidget_2->currentRow()]; // think.....
         CurrentIngridients.removeAt(ui->listWidget_2->currentRow());
         ui->listWidget_2->removeItemWidget(i);
         delete i;

        UpdateNutrition(-1, In);
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

void CreateRecipeWindow::UpdateNutrition(int s, Ingredient I)
{
    prt += I.protein*s;
    cal += I.calories*s;
    car += I.carbs*s;
    fat += I.fat*s;

    ui->ProtienInputLabel->setText(QString::number(prt));
    ui->CaloriesInputLabel->setText(QString::number(cal));
    ui->CarbsInputLabel->setText(QString::number(car));
    ui->FatInputLabel->setText(QString::number(fat));

}

void CreateRecipeWindow::on_RecipeBackButton_clicked()
{
    this->close();
}
