#include "ui_calcbmi.h"

CalcBMI::CalcBMI(QWidget *parent) :
   QDialog(parent),
   ui(new Ui::CalcBMI)
{
   ui->setupUi(this);
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
