#include "ui_calcbmi.h"
#include "calcbmi.h"
#include <QDebug>

CalcBMI::CalcBMI(QWidget *parent) :
   QDialog(parent),
   ui(new Ui::CalcBMI)
{
   ui->setupUi(this);
   qDebug() << "ignore this";
}

CalcBMI::~CalcBMI()
{
   delete ui;
}

void CalcBMI::UpdateMethod()
{

}

void CalcBMI::on_closeButton_clicked()
{
   CloseWindow(this);
}
