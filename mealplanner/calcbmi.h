#ifndef CALCBMI_H
#define CALCBMI_H

#include <QDialog>
#include "iupdatable.h"

namespace Ui {
class CalcBMI;
}

class CalcBMI : public QDialog, IUpdatable
{
    Q_OBJECT

    Q_INTERFACES(IUpdatable)

public:
    explicit CalcBMI(QWidget *parent = 0);
    ~CalcBMI();

private slots:
    void on_closeButton_clicked();

    void on_pushButton_clicked();

private:

    void UpdateMethod();

    Ui::CalcBMI *ui;
};

#endif // CALCBMI_H
