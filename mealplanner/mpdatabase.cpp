

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

void MpDatabase::addIngredientIntoDatabase(QString){
    //query to insert into ingredients table?
}

void MpDatabase::addRecipeIntoDatabase(QString){
     //query to insert into ingredients table?
}

void MpDatabase::lookUpDatabase(){
    /*still pretty generalized here, but given what the user is trying to look for
    do a query on that item and return the item to the user?
    */
}
