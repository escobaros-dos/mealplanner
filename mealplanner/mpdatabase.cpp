

#include "mpdatabase.h"

MpDatabase::MpDatabase()
{
  QStringList tables;
  QSqlQuery q;
  db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName("food.db");
  if(!db.open()) {
    //throw something
  }

  tables = db.tables();
  q = QSqlQuery(db);
  if(!tables.contains("meals",Qt::CaseInsensitive)) {
    q.exec("create table meals(date VARCHAR,recipe VARCHAR);");
  }
  if(!tables.contains("recipes",Qt::CaseInsensitive)) {
    q.exec("create table recipes(name VARCHAR,calories FLOAT,\
      protein FLOAT,ingredients TEXT,steps TEXT);");
  }
  if(!tables.contains("ingredients",Qt::CaseInsensitive)) {
    q.exec("create table ingredients(name VARCHAR,);");
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
