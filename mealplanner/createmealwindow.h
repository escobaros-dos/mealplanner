#ifndef CREATEMEALWINDOW_H
#define CREATEMEALWINDOW_H

#include <QDialog>

namespace Ui {
class CreateMealWindow;
}

class CreateMealWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CreateMealWindow(QWidget *parent = 0);
    ~CreateMealWindow();

private:
    Ui::CreateMealWindow *ui;
};

#endif // CREATEMEALWINDOW_H
