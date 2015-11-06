#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //MpDatabase TheDatabase;

    MpDatabase* DatabaseRef = new MpDatabase();

    QApplication a(argc, argv);


    MainWindow w(DatabaseRef);
    w.show();


    return a.exec();
}
