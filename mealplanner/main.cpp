#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{

   QApplication a(argc, argv);

   MainWindow w(&MpDatabase::GetDBInstance()); // passing a reference to the singleton db
   w.show();

   return a.exec();
}
