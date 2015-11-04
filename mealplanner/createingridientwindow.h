#ifndef CREATEINGRIDIENTWINDOW_H
#define CREATEINGRIDIENTWINDOW_H

#include <QDialog>
#include "ingredient.h"
#include "mpdatabase.h"


namespace Ui {
class CreateIngridientWindow;
}

class CreateIngridientWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CreateIngridientWindow(MpDatabase* db = 0, QWidget *parent = 0);
    ~CreateIngridientWindow();

private slots:

    void on_SaveIngtoDbButton_clicked();

    void on_IngBackButton_clicked();

private:


    MpDatabase* IngredientWinDB;
    Ui::CreateIngridientWindow *ui;
};

#endif // CREATEINGRIDIENTWINDOW_H
