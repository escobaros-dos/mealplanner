#ifndef VIEWMEALDETAILS_H
#define VIEWMEALDETAILS_H

#include <QDialog>
#include "mpdatabase.h"
#include "iupdatable.h"

namespace Ui {
class ViewMealDetails;
}

class ViewMealDetails : public QDialog, IUpdatable
{
    Q_OBJECT

    Q_INTERFACES(IUpdatable)

public:
    explicit ViewMealDetails(const QString &, MpDatabase *db, QWidget *parent = 0);
    ~ViewMealDetails();

     QList<QString> recipeName;

private slots:
     void on_MealsComboBox_activated(const QString &arg1);

private:
    Ui::ViewMealDetails *ui;


    void UpdateMethod();

    MpDatabase *database;

    QVector<QLabel*> VMDwinLabels;
    Recipe* CurrentRecipe;
    QString currentlySelectedDate;

    void updateIngredientListWidget(const QString &);
    void updateRecipeDirecetionTextBrowser(const QString&);
    void updateRecipeComboBox(const QList<QString> &);

};

#endif // VIEWMEALDETAILS_H
