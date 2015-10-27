#ifndef CREATEMEALWINDOW_H
#define CREATEMEALWINDOW_H

#include <QDialog>

namespace Ui {
class CreateMealWindow;
}

class CreateMealWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CreateMealWindow(QWidget *parent = 0);
    ~CreateMealWindow();

private slots:
    void on_pushButton_clicked();

    void on_CreateRecipeButton_clicked();

    void on_buttonBox_accepted();

    void on_lineEdit_2_textChanged(const QString &arg1);

private:
    Ui::CreateMealWindow *ui;
};

#endif // CREATEMEALWINDOW_H
