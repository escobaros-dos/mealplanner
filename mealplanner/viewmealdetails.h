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

     QList<QString> recipeName;

private slots:
     void on_MealsComboBox_activated(const QString &arg1);

private:
    Ui::ViewMealDetails *ui;

    MpDatabase *database;

    QString currentlySelectedDate;

    void updateIngredientListWidget(const QString &);
    void updateRecipeDirecetionTextBrowser(const QString &);
    void updateMealComboBox(const QList<QString> &);

};

#endif // VIEWMEALDETAILS_H
