#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    //MpDatabase TheDatabase;

    MpDatabase* DatabaseRef = new MpDatabase();

    QApplication a(argc, argv);
    MainWindow w = MainWindow(DatabaseRef);
    w.show();


    return a.exec();
}
