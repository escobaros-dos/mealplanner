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
    explicit CreateRecipeWindow(MpDatabase* db = 0, QWidget *parent = 0);
    ~CreateRecipeWindow();

private slots:

    void on_CreateIngridientButton_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Recipe NewRecipe;
    MpDatabase* RecipeDB;
    Ui::CreateRecipeWindow *ui;
};

#endif // CREATERECIPEWINDOW_H
