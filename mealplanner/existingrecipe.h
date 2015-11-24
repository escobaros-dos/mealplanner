#ifndef EXISTINGRECIPE_H
#define EXISTINGRECIPE_H

#include <QDialog>
#include "mpdatabase.h"
//#include "recipe.h"

#include "iupdatable.h"

namespace Ui {
class ExistingRecipe;
}

class ExistingRecipe : public QDialog, IUpdatable
{
    Q_OBJECT

    Q_INTERFACES(IUpdatable)

public:
    explicit ExistingRecipe(const QString &, MpDatabase *, QWidget *parent = 0);
    ~ExistingRecipe();

    QString currentDate;

private slots:
    void on_AddRecipeCurrentButton_clicked();

    void on_CloseWindowButton_clicked();

    void on_listWidget_clicked(const QModelIndex &index);

    void on_listWidget_currentRowChanged(int currentRow);

private:

    void populateList();

    void UpdateMethod();

   // QListIterator<Recipe> tempRecipeIterator;
    QVector<Recipe> tempRecipe;
    MpDatabase *eDatabase;
    Recipe* CurrentRecipe;
    QVector<QLabel*> ExistingWinLabels;

    Ui::ExistingRecipe *ui;
};

#endif // EXISTINGRECIPE_H
