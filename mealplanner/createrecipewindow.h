#ifndef CREATERECIPEWINDOW_H
#define CREATERECIPEWINDOW_H

#include <QDialog>
#include "mpdatabase.h"

namespace Ui {
class CreateRecipeWindow;
}

class CreateRecipeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CreateRecipeWindow(MpDatabase* db, QWidget *parent = 0);
    ~CreateRecipeWindow();

private slots:

    void on_CreateIngridientButton_clicked();

private:
    Recipe NewRecipe;
    MpDatabase* RecipeDB;
    Ui::CreateRecipeWindow *ui;
};

#endif // CREATERECIPEWINDOW_H
