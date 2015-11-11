#include "mpdatabase.h"

MpDatabase::MpDatabase()
{
  QStringList tables;
  QSqlQuery q;
  db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName("SQLiteMpDatabase.db");

  if(!db.open()) {
    //throw something
      qDebug() << db.lastError();
  }

  tables = db.tables();
  q = QSqlQuery(db);

  q.exec("PRAGMA foreign_keys = ON"); //just to make sure the foreign key support is on

  if(!tables.contains("meals",Qt::CaseInsensitive)) {
    q.exec("create table meals(mid integer primary key, mdate text, prop int);");
  }
  if(!tables.contains("recipes",Qt::CaseInsensitive)) {
    q.exec("create table recipes(recid integer primary key, rname text unique, steps text);");
  }
  if(!tables.contains("ingredients",Qt::CaseInsensitive)) {
    q.exec("create table ingredients(ingid integer primary key, iname text unique,"
           "cal int, carbs int, fat int, protein int);");
  }
/*
  q.exec("create table relate (rIdRelate int, iIdRelate int, "
         "foreign key (rIdRelate) reference recipes(recid)), "
         "foreign key (iIdRelate) reference ingredients(ingid));");
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

    //add recipe name into the query
    //call addIngredient and pass in recipe.ingredient[x]
    //loop through until the vector is finished
    //update the relations table?

    //QSqlQuery q = QSqlQuery(db);
    QSqlQuery q;
    QString tempRecipeId;

    q.prepare("insert into recipes "
              "values (:name, :steps)");

    q.bindValue(":name", recipe.getName()); //name is private


    //concatenate vector before tossing into the database
    //fix later ;)
    //q.bindValue(":steps", recipe.catSteps);

    q.exec();


   for(int i = 0; i < recipe.ingredients.size(); i++)
   {
       addIngredient(recipe.ingredients[i]);

       updateRelationTable(recipe.getName(), recipe.ingredients[i].getName()); //pairs the recipe id with the ingredients id
                                                                               //there has to be a better way of doing this function
   }



}

void MpDatabase::addIngredient(const Ingredient &ingredient)
{

    //unique constraint has been added to the name column of the ingredient, to prevent duplication

    qDebug() << "inserting: " << ingredient.name <<" with calories: "<< ingredient.calories;

   // QSqlQuery q = QSqlQuery(db);
    QSqlQuery q;

    qDebug() << "query created";
    q.prepare("INSERT INTO ingredients(iname, cal, carbs, fat, protein) "
              "VALUES (:iname, :cal, :carbs, :fat, :protein)");

    qDebug() << "finished prepairing " << ingredient.name;
    //q.bindValue(":ingid", ingredient.id);
    q.bindValue(":iname", ingredient.name);
    q.bindValue(":cal", ingredient.getCalories());
    q.bindValue(":carbs", ingredient.getCarbs());
    q.bindValue(":fat", ingredient.getFat());
    q.bindValue(":protein", ingredient.getProtein());
    q.exec();

    qDebug() << "finished inserting: " << ingredient.name;

}

QVector<QString> MpDatabase::getRecipesByIngredient(QString &ing){

    QSqlQuery q = QSqlQuery(db); //this seems kind of reptitive us a macro?

    QVector<QString> tempQueryResult;

    //maybe considering on using joins

    q.prepare("select rname from recipes where recid in "
              "(select recidf from relate where ingidf in "
              "(select ingid from ingredients where iname = :ing));"); //rewrite the query using IN

    q.bindValue(":ing", ing);
    q.exec();

    while(q.next())
    {
        tempQueryResult.append(q.value(0).toString());
    }


    return tempQueryResult;

}

void MpDatabase::updateRelationTable(const QString &recipeName, const QString &ingredientName){

    //for each ingredient id associated with the new recipe, relate those ingredients with the newly inserted recipe id

    //can we use one QSqlQuery object to do multiple queries or should we use multiple QSqlQuery

    QSqlQuery q = QSqlQuery(db); // uhhh check this declaration maybe....

    QString rId;
    QString iId;

    q.prepare("select recid from recipes where rname = :recipeName");
    q.bindValue(":recipeName", recipeName);
    q.exec();
    q.next();
    rId = q.value(0).toString();


    q.prepare("select ingid from ingredients where iname = :ingredientName");
    q.bindValue(":ingredientName", ingredientName);
    q.exec();
    q.next();
    iId = q.value(0).toString();

    q.prepare("insert into relate (rIdRelate, iIdRelate) values (:rId, :iId);");
    q.bindValue(":rId", rId);
    q.bindValue(":iId", iId);
    q.exec();


}
