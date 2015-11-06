#include "viewmealdetails.h"
#include "ui_viewmealdetails.h"

ViewMealDetails::ViewMealDetails(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewMealDetails)
{
    ui->setupUi(this);
}

ViewMealDetails::~ViewMealDetails()
{
    delete ui;
}
