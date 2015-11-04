#ifndef CREATEMEALWINDOW_H
#define CREATEMEALWINDOW_H

#include <QDialog>

class MpDatabase;

namespace Ui {
class CreateMealWindow;
}

class CreateMealWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CreateMealWindow(MpDatabase* db = 0, QWidget *parent = 0);
    ~CreateMealWindow();

private slots:

    void on_CreateRecipeButton_clicked();

    void on_buttonBox_accepted();

    void on_lineEdit_2_textChanged(const QString &arg1);

private:
    MpDatabase* MealWinDB;
    Ui::CreateMealWindow *ui;
};

#endif // CREATEMEALWINDOW_H
