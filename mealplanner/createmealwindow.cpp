#include "createmealwindow.h"
#include "ui_createmealwindow.h"

CreateMealWindow::CreateMealWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateMealWindow)
{
    ui->setupUi(this);
}

CreateMealWindow::~CreateMealWindow()
{
    delete ui;
}
