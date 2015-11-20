#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    MpDatabase* DatabaseRef = &MpDatabase::GetDBInstance();



    QApplication a(argc, argv);


    MainWindow w(DatabaseRef);
    w.show();


    return a.exec();
}
