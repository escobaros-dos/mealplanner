#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "createmealwindow.h"
#include "recipebook.h"
#include "viewmealdetails.h"
#include "createrecipewindow.h"


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

//-------------------------------------------------------------------
void MainWindow::on_RecipeBookButton_clicked()//opens recipe book
{

    RecipeBook RB;
    RB.setModal(false);
    RB.exec();
    //ui -> stackedWidget -> setCurrentIndex(2);
    //qDebug("index change");//error check
}

void MainWindow::on_ViewDetailsButton_clicked()
{
    ViewMealDetails MealDetailsWindow;
    MealDetailsWindow.setModal(false);
    MealDetailsWindow.exec();
   // ui -> stackedWidget -> setCurrentIndex(1);
    //qDebug("index change");//error check
}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{

    //if the user clicks on the same date multiple times the list will keep adding items onto the widget

    currentlySelectedDate = date.toString();

    //update the listOfMeals widget with the name of the meals?? from the database based on the date

    //ui->listMealName->addItem("something");
    //ui->listMealName->addItem("something2");
    ui->ListMealsTextBrowser->setText("someting");


    //qDebug() << currentlySelectedDate;
}

void MainWindow::on_calendarWidget_selectionChanged()
{
    //ui->listMealName->clear();
    ui->ListMealsTextBrowser->clear();
}



void MainWindow::on_CreateRecipeButton_clicked()
{
    QString testfornow = " ";
    //CreateRecipeWindow RecipeWin(testfornow, MainDB);
    CreateRecipeWindow RecipeWin(testfornow, MainDB);
    RecipeWin.setModal(false);
    RecipeWin.exec();
}
