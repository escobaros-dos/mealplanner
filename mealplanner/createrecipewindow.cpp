#include "createrecipewindow.h"
#include "ui_createrecipewindow.h"
#include "createingridientwindow.h"
#include <QDebug>

CreateRecipeWindow::CreateRecipeWindow(MpDatabase* db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateRecipeWindow)
{
    ui->setupUi(this);
    RecipeDB = db;


    //foreach(QString s, RecipeDB->getIngredientNames())
    //{
    //ui->listWidget->addItem(s);
    //}

    QVector<QString> names = RecipeDB->getIngredientNames();
    for(int i = 0; i<names.size(); i++)
    {
        ui->listWidget->addItem(names[i]);
    }

}

CreateRecipeWindow::~CreateRecipeWindow()
{
    delete ui;
    qDebug() << "recipe window destoried";
}

void CreateRecipeWindow::on_CreateIngridientButton_clicked()
{
    CreateIngridientWindow IngridientWin(RecipeDB);
    IngridientWin.setModal(false);
    IngridientWin.exec();
}

void CreateRecipeWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    //test for list widget for selection...

   //item->setText("test");

    //QString selected = item->text();

}

void CreateRecipeWindow::on_pushButton_2_clicked()
{
    foreach(QListWidgetItem *i, ui->listWidget->selectedItems())
    {
        qDebug() << "selceted." << i->text();
        ui->listWidget_2->addItem(i->text());
    }

}

void CreateRecipeWindow::on_pushButton_3_clicked()
{
    foreach(QListWidgetItem *i, ui->listWidget_2->selectedItems())
    {
        qDebug() << "selceted." << i->text();
        //ui->listWidget_2->removeItemWidget(i);
        delete i;
    }


}
