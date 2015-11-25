#ifndef CREATERECIPEWINDOW_H
#define CREATERECIPEWINDOW_H

#include <QDialog>
#include "mpdatabase.h"
#include <QWidgetItem>
#include <QListWidgetItem>
#include "iupdatable.h"

namespace Ui {
class CreateRecipeWindow;
}

class CreateRecipeWindow : public QDialog, IUpdatable
{
    Q_OBJECT

    Q_INTERFACES(IUpdatable)

public:
    explicit CreateRecipeWindow(QString& d, MpDatabase* db = 0, QWidget *parent = 0);
    ~CreateRecipeWindow();


private slots:

    void on_CreateIngridientButton_clicked(); //opens create ingredient window

    void on_RecipeSaveToDbButton_clicked(); // saves the created recipe to database

    void on_RemoveFromSelected_clicked(); // removes a selected ingredient from the list of recipe ingredients

    void on_AddFromDatabase_clicked(); // adds the selected ingredient to the list of recipe ingredients

    void on_RecipeBackButton_clicked(); // closes the create recipe window

private:

    QString currentDate;
    QVector<QLabel*> RWinLabels;
    int UpdateSign = 0;

    void UpdateInterfaceValues(int sign, Ingredient in);
    void UpdateRecipeList();
    void UpdateMethod();
    QVector<Ingredient> CurrentIngridients;

    Ingredient* ChangedIngredient;
    MpDatabase* RecipeDB;
    Ui::CreateRecipeWindow *ui;
};

#endif // CREATERECIPEWINDOW_H
