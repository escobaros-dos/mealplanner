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
   // CreateIngridientWindow(MpDatabase* db);
    ~CreateIngridientWindow();

private slots:
    void on_lineEdit_textEdited(const QString &arg1);

    void on_protienEdit_textEdited(const QString &arg1);

    void on_CalorieEdit_textEdited(const QString &arg1);

    void on_CarbEdit_textEdited(const QString &arg1);

    void on_FatEdit_textEdited(const QString &arg1);

    void on_buttonBox_accepted();

    void on_pushButton_clicked();

private:

    Ingredient NewIngredient;

    MpDatabase* IngredientWinDB;
    Ui::CreateIngridientWindow *ui;
};

#endif // CREATEINGRIDIENTWINDOW_H
