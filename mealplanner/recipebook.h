#ifndef RECIPEBOOK_H
#define RECIPEBOOK_H

#include <QDialog>

namespace Ui {
class RecipeBook;
}

class RecipeBook : public QDialog
{
    Q_OBJECT

public:
    explicit RecipeBook(QWidget *parent = 0);
    ~RecipeBook();

private:
    Ui::RecipeBook *ui;
};

#endif // RECIPEBOOK_H
