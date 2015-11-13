#ifndef CREATERECIPEWINDOW_H
#define CREATERECIPEWINDOW_H

#include <QDialog>
#include "mpdatabase.h"
#include <QWidgetItem>
#include <QListWidgetItem>

namespace Ui {
class CreateRecipeWindow;
}

class CreateRecipeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CreateRecipeWindow(QString& d, MpDatabase* db = 0, QWidget *parent = 0);
    ~CreateRecipeWindow();

private slots:

    void on_CreateIngridientButton_clicked();

    void on_RecipeSaveToDbButton_clicked();

    void on_RemoveFromSelected_clicked();

    void on_AddFromDatabase_clicked();

    void on_RecipeBackButton_clicked();

private:

    void UpdateNutrition(int sign, Ingredient in);
    void UpdateRecipeList();
    QVector<Ingredient> CurrentIngridients;

    MpDatabase* RecipeDB;
    Ui::CreateRecipeWindow *ui;
};

#endif // CREATERECIPEWINDOW_H
