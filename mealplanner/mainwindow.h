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

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();



    void on_actionFna_triggered();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_actionRecipe_Book_2_triggered();

    void on_actionCreate_Recipe_triggered();

    void on_pushButton_4_clicked();

    void on_CreateMealButton_clicked();

    void on_textBrowser_textChanged();

private:
    MpDatabase* MainDB;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
