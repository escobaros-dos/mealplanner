#ifndef MPDATABASE_H
#define MPDATABASE_H

#include <QObject>
#include <QtSql>


class MpDatabase
{
public:
    MpDatabase();

protected:
    void addRecipeIntoDatabase(QString);
    void addIngredientIntoDatabase(QString);
    void lookUpDatabase(); //kind of want to make this as a template
    //more to come

private:
    QSqlDatabase db;

signals:

public slots:
};

#endif // MPDATABASE_H
