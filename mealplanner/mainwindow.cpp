#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    ui-> stackedWidget -> setCurrentIndex(1);
    qDebug("index change");//error check
}

void MainWindow::on_pushButton_3_clicked()
{
    ui -> stackedWidget -> setCurrentIndex(2);
    qDebug("index change");//error check
}

void MainWindow::on_actionFna_triggered()
{
    ui -> stackedWidget -> setCurrentIndex(0);
    qDebug("index change");//error check
}
