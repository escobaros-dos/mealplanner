#ifndef VIEWMEALDETAILS_H
#define VIEWMEALDETAILS_H

#include <QDialog>
#include "mpdatabase.h"

namespace Ui {
class ViewMealDetails;
}

class ViewMealDetails : public QDialog
{
    Q_OBJECT

public:
    explicit ViewMealDetails(const QString &, MpDatabase *db, QWidget *parent = 0);
    ~ViewMealDetails();

private:
    Ui::ViewMealDetails *ui;

    MpDatabase *database;

    QString currentDate;

    void updateIngredientTextBrowser();
    void updateRecipeDirecetionTextBrowser();
    void updateMealComboBox();

};

#endif // VIEWMEALDETAILS_H
