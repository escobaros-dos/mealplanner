#ifndef VIEWMEALDETAILS_H
#define VIEWMEALDETAILS_H

#include <QDialog>

namespace Ui {
class ViewMealDetails;
}

class ViewMealDetails : public QDialog
{
    Q_OBJECT

public:
    explicit ViewMealDetails(QWidget *parent = 0);
    ~ViewMealDetails();

private:
    Ui::ViewMealDetails *ui;
};

#endif // VIEWMEALDETAILS_H
