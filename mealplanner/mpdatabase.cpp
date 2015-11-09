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

  q.exec("create table relate (rIdRelate int, iIdRelate int, "
         "foreign key (rIdRelate) references recipes(recid)), "
         "foreign key (iIdRelate) references ingredients(ingid));");

}

MpDatabase::~MpDatabase() {
  db.close();
}

Ingredient MpDatabase::getIngredientByName(QString name) {

    Ingredient i;
    QSqlQuery q;
    q.prepare("SELECT * FROM ingredients WHERE iname = :n");
    q.bindValue(":n",name);
    q.exec();
    q.next();
    i = Ingredient(q.value(5).toInt(),q.value(4).toInt(),q.value(3).toInt(),q.value(2).toInt(),q.value(1).toString());
    return i;
}

Recipe MpDatabase::getRecipeByName(QString name) {
    //incomplete (no relational table?)
    Recipe r;
    QSqlQuery q;
    q.prepare("SELECT * FROM recipes WHERE rname = :n");
    q.bindValue(":n",name);
    q.exec();
    q.next();
    r = Recipe();
    return r;
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


QVector<QString> MpDatabase::getNameFromDatabase(const QString &column, const QString &table)
{
    QVector<QString> names;
    QSqlQuery q = QSqlQuery(db);
    q.prepare("SELECT :column FROM :table;");
    q.bindValue(":column", column);
    q.bindValue(":table", table);
    q.exec();

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

    QSqlQuery q = QSqlQuery(db);
    QString tempRecipeId;
    q.prepare("INSERT INTO recipes(rname, steps)"
              "VALUES (:name, :steps)");

    q.bindValue(":name", recipe.getName()); //name is private


    //concatenate vector before tossing into the database
    //fix later ;)
    q.bindValue(":steps", "NOT IMPLEMENTED");

    q.exec();

    foreach(Ingredient i,recipe.ingredients.toList()) {
        addIngredient(i);
        updateRelationTable(recipe.getName(),i.getName());
    }

   //for(int i = 0; i < recipe.ingredients.size(); i++){
       //qDebug() << QString(i);
       //qDebug() << recipe.ingredients[i];
       //addIngredient(recipe.ingredients[i]);
       //qDebug() << recipe.ingredients[i].getName();
       //updateRelationTable(recipe.getName(), recipe.ingredients[i].getName()); //pairs the recipe id with the ingredients id
                                                                               //there has to be a better way of doing this function
   //}



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

    QSqlQuery q;
    int recid = getRecipeIDByName(recipeName);
    int ingid = getIngredientIDByName(ingredientName);

    q.prepare("insert into relate (rIdRelate, iIdRelate) values (:rId, :iId);");
    q.bindValue(":rId", recid);
    q.bindValue(":iId", ingid);
    q.exec();


}

int MpDatabase::getIngredientIDByName(const QString &ingredient) {
    QSqlQuery q;
    q.prepare("SELECT ingid FROM ingredients WHERE iname = :name;");
    q.bindValue(":name",ingredient);
    q.exec();
    q.next();
    return q.value(0).toInt();
}

int MpDatabase::getRecipeIDByName(const QString &recipe) {
    QSqlQuery q;
    q.prepare("SELECT recid FROM recipes WHERE rname = :name;");
    q.bindValue(":name",recipe);
    q.exec();
    q.next();
    return q.value(0).toInt();
}
