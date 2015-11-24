#ifndef VIEWMEALDETAILS_H
#define VIEWMEALDETAILS_H

#include <QDialog>
//#include <QListIterator>
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

     //QList<Recipe> recipeList;

private slots:
     void on_MealsComboBox_activated(const QString &arg1);

     void on_MealsComboBox_activated(int index);

     void on_VMD_Okay_clicked();

private:
    Ui::ViewMealDetails *ui;

    QList<Recipe> recipeList;

    void UpdateMethod();

    MpDatabase *database;

    QVector<QLabel*> VMDwinLabels;
    Recipe* CurrentRecipe;
    QString currentlySelectedDate;

    void updateIngredientListWidget(const Recipe &);
    void updateRecipeDirecetionTextBrowser(const QString&);
    void updateRecipeComboBox(const QList<Recipe> &);

};

#endif // VIEWMEALDETAILS_H
