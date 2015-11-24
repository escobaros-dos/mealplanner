#include "recipebook.h"
#include "ui_recipebook.h"

RecipeBook::RecipeBook(QWidget *parent) :
   QDialog(parent),
   ui(new Ui::RecipeBook)
{
   ui->setupUi(this);
}

RecipeBook::~RecipeBook()
{
   delete ui;
}
