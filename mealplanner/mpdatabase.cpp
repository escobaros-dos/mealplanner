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

  q.exec("PRAGMA foreign_keys = ON");

  if(!tables.contains("meals",Qt::CaseInsensitive)) {
    q.exec("create table meals(mid int primary key, mdate date, prop int);");
  }
  if(!tables.contains("recipes",Qt::CaseInsensitive)) {
    q.exec("create table recipes(recid int primary key, rname text, steps text);");
  }
  if(!tables.contains("ingredients",Qt::CaseInsensitive)) {
    q.exec("create table ingredients(ingid int primary key, iname text,"
           "cal int, carbs int, fat int, protein int);");
  }
/*
  q.exec("create table recing (recidf int, ingidf int, "
         "foreign key (recidf) reference recipes(recid)), "
         "foreign key (ingid) reference ingredients(ingid));");
*/
}

MpDatabase::~MpDatabase() {
  db.close();
}

Ingredient MpDatabase::getIngredientByName(QString) {


    //return Ingredient;
}

Recipe MpDatabase::getRecipeByName(QString) {


   // Recipe rec = new Recipe;

   //return Recipe();
}


//use a template??

QVector<QString> MpDatabase::getRecipeNames() {
  QVector<QString> names;
  QSqlQuery q = QSqlQuery(db);
  q.exec("SELECT rname FROM recipes;");
  while(q.next()) {
    names.append(q.value(0).toString());
  }
  return names;
}

QVector<QString> MpDatabase::getIngredientNames() {
  QVector<QString> names;
  QSqlQuery q = QSqlQuery(db);
  q.exec("SELECT iname FROM ingredients;");
  while(q.next()) {
    names.append(q.value(0).toString());
  }
  return names;
}

void MpDatabase::addRecipe(const Recipe &recipe){
    QSqlQuery q = QSqlQuery(db);

    q.prepare("insert into recipes "
              "values (:name, :steps)");

    q.bindValue(":name", recipe.getName()); //name is private


    //concatenate vector before tossing into the database
    //fix later ;)
    //q.bindValue(":steps", recipe.catSteps);


    q.exec();

    //when adding recipes check for ingredients in the database for repetitions
    //update the relations table if a recipe uses any ingredients that does in the relations table

}

void MpDatabase::addIngredient(const Ingredient &ingredient){
    QSqlQuery q = QSqlQuery(db);
    q.prepare("insert into ingredients "
              "values (:name, :cal, :carbs, :fat, :pro)");
    q.bindValue(":name", ingredient.getName());
    q.bindValue(":cal", ingredient.getCalories());
    q.bindValue(":carbs", ingredient.getCarbs());
    q.bindValue(":fat", ingredient.getFat());
    q.bindValue(":pro", ingredient.getProtein());
    q.exec();
}

QVector<QString> MpDatabase::getRecipesByIngredient(QString &ing){

    QSqlQuery q = QSqlQuery(db); //this seems kind of reptitive us a macro?

    QVector<QString> tempQueryResult;

    //maybe considering on using joins

    q.prepare("select rname from recipes where recid = "
              "(select recidf from recing where ingidf = "
              "(select ingid from ingredients where iname = :ing"); //needs testing

    q.bindValue(":ing", ing);
    q.exec();

    while(q.next())
    {
        tempQueryResult.append(q.value(0).toString());
    }


    return tempQueryResult;



}

