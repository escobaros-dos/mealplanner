#ifndef CREATERECIPEWINDOW_H
#define CREATERECIPEWINDOW_H

#include <QDialog>

namespace Ui {
class CreateRecipeWindow;
}

class CreateRecipeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CreateRecipeWindow(QWidget *parent = 0);
    ~CreateRecipeWindow();

private:
    Ui::CreateRecipeWindow *ui;
};

#endif // CREATERECIPEWINDOW_H
