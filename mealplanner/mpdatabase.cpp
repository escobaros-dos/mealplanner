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

MpDatabase::~MpDatabase() {
  db.close();
}

Ingredient MpDatabase::getIngredientByName(QString) {
  return Ingredient();
}

Recipe MpDatabase::getRecipeByName(QString) {
  return Recipe();
}

QVector<QString> MpDatabase::getRecipeNames() {
  QVector<QString> names;
  QSqlQuery q = QSqlQuery(db);
  q.exec("SELECT name FROM recipes;");
  while(q.next()) {
    names.append(q.value(0).toString());
  }
  return names;
}

QVector<QString> MpDatabase::getIngredientNames() {
  QVector<QStrings> names;
  QSqlQuery q = QSqlQuery(db);
  q.exec("SELECT name FROM ingredients;");
  while(q.next()) {
    names.append(q.value(0).toString());
  }
  return names;
}

