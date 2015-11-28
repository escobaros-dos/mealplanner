#include "ui_calcbmi.h"
#include "calcbmi.h"
#include <QDebug>

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

void CalcBMI::on_pushButton_clicked()
{
    float bmi;
    float height;
    float feet = ui -> FeetLineEdit -> text().toInt();
    float inches = ui -> InchesLineEdit -> text().toInt();
    float weight = ui -> WeightLineEdit -> text().toInt();

    height = feet * 12 +inches;
    height = (height*height);
    weight = (weight*703);

    bmi = ((weight)/(height));
    QString b = QString::number(bmi);
    ui->BMILineEdit->setText(b);
}
