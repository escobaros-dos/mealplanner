#include "iupdatable.h"


void IUpdatable::CloseWindow(QWidget* W)
{
   W->close();
   return;
}

void IUpdatable::UpdateNutrition(const QVector<QLabel*>& Labels)
{

   UpdateMethod();

   //Labels[0].setText();
   Labels[0]->setText(QString::number(prt));
   Labels[1]->setText(QString::number(cal));
   Labels[2]->setText(QString::number(car));
   Labels[3]->setText(QString::number(fat));

   return;

}

void IUpdatable::UpdateStatus(QLabel* L, const QString& S)
{
   // needs changing.....
   L->setText(S + " has been succesfully added to the database.");
   return;
}

void IUpdatable::SetLabels(const QVector<QLabel*>& Labels, int value)
{
   foreach(QLabel* l, Labels.toList())
   {
      l->setText(QString::number(value));
   }
   return;
}
