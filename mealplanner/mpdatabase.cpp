

#include "mpdatabase.h"

MpDatabase::MpDatabase()
{
  QStringList tables;
  QSqlQuery q;
  db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName("recipes.db");
  if(!db.open()) {
    //throw something
  }

  tables = db.tables();
  q = QSqlQuery(db);
  if(!tables.contains("recipes",Qt::CaseInsensitive)) {
    q.exec("create table recipes(name VARCHAR,date TEXT,calories FLOAT,\
      protein FLOAT,ingredients TEXT,steps TEXT");
  }

}
