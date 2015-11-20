#ifndef CREATEINGRIDIENTWINDOW_H
#define CREATEINGRIDIENTWINDOW_H

#include <QDialog>
#include "ingredient.h"
#include "mpdatabase.h"
#include "iupdatable.h"

namespace Ui {
class CreateIngridientWindow;
}

class CreateIngridientWindow : public QDialog, IUpdatable
{
    Q_OBJECT

    Q_INTERFACES(IUpdatable)

public:
    explicit CreateIngridientWindow(MpDatabase* db = 0, QWidget *parent = 0);
    ~CreateIngridientWindow();

private slots:

    void on_SaveIngtoDbButton_clicked();

    void on_IngBackButton_clicked();

private:

    void UpdateMethod();
    MpDatabase* IngredientWinDB;
    Ui::CreateIngridientWindow *ui;
};

#endif // CREATEINGRIDIENTWINDOW_H
