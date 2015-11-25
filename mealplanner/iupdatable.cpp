#include "iupdatable.h"


void IUpdatable::CloseWindow(QWidget* W)
{
   W->close();
   return;
}

void IUpdatable::UpdateNutrition(const QVector<QLabel*>& Labels)
{

   UpdateMethod();

<<<<<<< HEAD
    Labels[0]->setText(QString::number(Value1));
    Labels[1]->setText(QString::number(Value2));
    Labels[2]->setText(QString::number(Value3));
    Labels[3]->setText(QString::number(Value4));
=======
   //Labels[0].setText();
   Labels[0]->setText(QString::number(prt));
   Labels[1]->setText(QString::number(cal));
   Labels[2]->setText(QString::number(car));
   Labels[3]->setText(QString::number(fat));
>>>>>>> 0803ce7d742e06ec862880cebf998d19d105797d

   return;

}

void IUpdatable::UpdateStatus(QLabel* L, const QString& S, const QString& StatusMsg)
{
<<<<<<< HEAD
    L->setText(S + StatusMsg);
    return;
=======
   // needs changing.....
   L->setText(S + " has been succesfully added to the database.");
   return;
>>>>>>> 0803ce7d742e06ec862880cebf998d19d105797d
}

void IUpdatable::SetLabels(const QVector<QLabel*>& Labels, int value)
{
   foreach(QLabel* l, Labels.toList())
   {
      l->setText(QString::number(value));
   }
   return;
}
