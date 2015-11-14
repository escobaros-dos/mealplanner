#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mpdatabase.h"
//class MpDatabase;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(MpDatabase* db, QWidget *parent = 0);

    ~MainWindow();

    QString currentlySelectedDate;

protected:

    void updateMealListWidget();

private slots:

    void on_pushButton_2_clicked();

    void on_RecipeBookButton_clicked();


    void on_actionFna_triggered();

    void on_ViewDetailsButton_clicked();

    void on_actionRecipe_Book_2_triggered();

    void on_actionCreate_Recipe_triggered();

    void on_pushButton_4_clicked();

    void on_calendarWidget_clicked(const QDate &date);

    void on_calendarWidget_selectionChanged();


    void on_CreateRecipeButton_clicked();

private:
    MpDatabase* MainDB;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
