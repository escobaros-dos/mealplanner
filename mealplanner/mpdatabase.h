#ifndef MPDATABASE_H
#define MPDATABASE_H

#include <QObject>
#include <QtSql>


class MpDatabase
{
public:
    MpDatabase();

private:
    QSqlDatabase db;

signals:

public slots:
};

#endif // MPDATABASE_H
