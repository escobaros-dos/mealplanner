#include "iupdatable.h"


void IUpdatable::CloseWindow(QWidget* W)
{
   W->close();
   return;
}

void IUpdatable::UpdateNutrition(const QVector<QLabel*>& Labels)
{

   UpdateMethod();

    Labels[0]->setText(QString::number(Value1));
    Labels[1]->setText(QString::number(Value2));
    Labels[2]->setText(QString::number(Value3));
    Labels[3]->setText(QString::number(Value4));

   return;

}

void IUpdatable::UpdateStatus(QLabel* L, const QString& S, const QString& StatusMsg)
{
    L->setText(S + StatusMsg);
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
