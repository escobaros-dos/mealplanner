#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "createmealwindow.h"
#include "recipebook.h"


MainWindow::MainWindow(MpDatabase* db, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainDB = db;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{   //This should go to the CREATE MEAL PLAN SCREEN
    //ui-> stackedWidget -> setCurrentIndex(1);
    //qDebug("index change");//error check
}
//-------------------------------------------------------------------
void MainWindow::on_pushButton_3_clicked()//opens recipe book
{

    RecipeBook RB;
    RB.setModal(false);
    RB.exec();
    //ui -> stackedWidget -> setCurrentIndex(2);
    qDebug("index change");//error check
}

//----------------------------------------Stacked Widget Back Buttons----------------------------------
void MainWindow::on_pushButton_7_clicked()//StackedWidget(1)
{
    ui -> stackedWidget -> setCurrentIndex(0);
    qDebug("index change");//error check
}
//----------------------------------------------------------
void MainWindow::on_pushButton_8_clicked()//StackedWidget(2)
{
    ui -> stackedWidget -> setCurrentIndex(0);
    qDebug("index change");//error check
}
//--------------------------------------------------------

void MainWindow::on_pushButton_6_clicked()
{
   // ui -> stackedWidget -> setCurrentIndex(1);
    //qDebug("index change");//error check
}
//----------------------------------------------MainWidget Menu Bar
//--------------------------------------------------------
void MainWindow::on_actionFna_triggered()// this is the Home button
{
    ui -> stackedWidget -> setCurrentIndex(0);
    qDebug("index change");//error check
}
//------------------------------------------------------
void MainWindow::on_actionRecipe_Book_2_triggered()//menu tab button "Recipe book" opens recipe book
{

    RecipeBook RB;
    RB.setModal(false);
    RB.exec();
    //ui -> stackedWidget -> setCurrentIndex(2);
    //qDebug("index change");//error check
}
//------------------------------------------------------
void MainWindow::on_actionCreate_Recipe_triggered()//menu tab button "Create recipe" opens CREATE RECIPS
{

    //ui -> stackedWidget -> setCurrentIndex(1);
    //qDebug("index change");//error check
}

void MainWindow::on_pushButton_4_clicked()
{

}

void MainWindow::on_CreateMealButton_clicked()
{
    CreateMealWindow MealWin(MainDB);
    MealWin.setModal(false);
    MealWin.exec();
}


void MainWindow::on_calendarWidget_clicked(const QDate &date)
{

    //if the user clicks on the same date multiple times the list will keep adding items onto the widget

    currentlySelectedDate = date.toString();

    //update the listOfMeals widget with the name of the meals?? from the database based on the date

    ui->listMealName->addItem("something");
    ui->listMealName->addItem("something2");


    //qDebug() << currentlySelectedDate;
}

void MainWindow::on_calendarWidget_selectionChanged()
{
    ui->listMealName->clear();
}
