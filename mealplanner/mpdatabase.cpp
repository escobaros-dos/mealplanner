#include "mpdatabase.h"



MpDatabase::MpDatabase()
{
  QStringList tables;
  //QSqlQuery q;
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

    //may need to change the meals to just the date
    q.exec("create table meals(mid integer primary key, mdate text unique);");
  }
  if(!tables.contains("recipes",Qt::CaseInsensitive)) {
    q.exec("create table recipes(recid integer primary key, rname text unique, steps text);");
  }
  if(!tables.contains("ingredients",Qt::CaseInsensitive)) {
    q.exec("create table ingredients(ingid integer primary key, iname text unique,"
           "cal int, carbs int, fat int, protein int);");
  }

  //create relation table for recipe and ingredient

  q.exec("create table relate (rIdRelate int, iIdRelate int, "
         "foreign key (rIdRelate) references recipes(recid), "
         "foreign key (iIdRelate) references ingredients(ingid));");

  //create relation table for recipe and date
  //may need to change the meals relation if meals table is modified or removed

  q.exec("create table dateRecipeRelate (dnrmid int, dnrrid int, "
         "foreign key (dnrmid) references meals(mid),"
         "foreign key (dnrrid) references recipes(recid));");

  q.exec("create table steps (rId int, step text, "
         "foreign key (rId) references recipes(recid));");

}

MpDatabase& MpDatabase::GetDBInstance()
{
    static MpDatabase DB;
    return DB;
}

//MpDatabase::~MpDatabase() {
//  db.close();
//}

Ingredient MpDatabase::getIngredientByName(QString name) {

    //Ingredient i;
    //QSqlQuery q;
    q.prepare("SELECT * FROM ingredients WHERE iname = :n");
    q.bindValue(":n",name);
    q.exec();
    q.next();
    //Ingredient i = Ingredient(q.value(5).toInt(),q.value(4).toInt(),q.value(3).toInt(),q.value(2).toInt(),q.value(1).toString());
        //do this vvvvvvv,   not this ^^^^^^^^^
    Ingredient i(q.value(5).toInt(),q.value(4).toInt(),q.value(3).toInt(),q.value(2).toInt(),q.value(1).toString());
    return i;
}

Recipe MpDatabase::getRecipeByName(QString name)
{
    //incomplete (no relational table?)
    //Recipe r;
    //QSqlQuery q;
    q.prepare("SELECT recid, rname, steps FROM recipes WHERE rname = :n");
    q.bindValue(":n",name);
    q.exec();
    q.next();
    //r = Recipe(); // ISSUE: This is not finished....it returns a

    QString tempSteps = q.value(2).toString();
    QString tempName = q.value(1).toString();

    QVector<QString> IngNames = getIngredientsByRecipe(name);
    QVector<Ingredient> Ings;

    foreach(QString s, IngNames.toList())
    {
        Ings.push_back(getIngredientByName(s));
    }

    //BUG
    Recipe r(Ings, tempSteps, tempName);
    qDebug() << "string q vualue 2...." << q.value(2);
    //qDebug() << "to int q value 2...." << q.value(0).toInt();
    return r;
}

QVector<QString> MpDatabase::getRecipeNames() {
  QVector<QString> names;
  //QSqlQuery q = QSqlQuery(db);
  q.exec("SELECT rname FROM recipes;");
  while(q.next()) {
    names.append(q.value(0).toString());
  }
  return names;
}

QVector<QString> MpDatabase::getIngredientNames() {
  QVector<QString> names;
  //QSqlQuery q = QSqlQuery(db);
  q.exec("SELECT iname FROM ingredients;");
  while(q.next()) {
    names.append(q.value(0).toString());
  }
  return names;
}

/*
QVector<QString> MpDatabase::getNameFromDatabase(const QString &column, const QString &table)
{
    QVector<QString> names;
    //QSqlQuery q = QSqlQuery(db);
    q.prepare("SELECT :column FROM :table;");
    q.bindValue(":column", column);
    q.bindValue(":table", table);
    q.exec();

    while(q.next()) {
      names.append(q.value(0).toString());
    }
    return names;
}
*/

//-----------------------------------------------
//-------adding into the database
//-----------------------------------------------


void MpDatabase::addRecipe(const Recipe &recipe, const QString Date)
{

    //add recipe name into the query
    //call addIngredient and pass in recipe.ingredient[x]
    //loop through until the vector is finished
    //update the relations table?

    QString tempRecipeId;

    q.prepare("INSERT INTO recipes(rname, steps)"
              "VALUES (:name, :steps)");

    q.bindValue(":name", recipe.getName()); //name is private

    q.bindValue(":steps", recipe.GetDirections());

    q.exec();

    //need to update the date and recipe relations

    //updateMealRecipeRelation();

    q.prepare("SELECT recid FROM recipes where rname = :name;");
    q.bindValue(":name",recipe.rname);
    q.exec();
    q.next();

    tempRecipeId=q.value(0).toString();

    addMeal(Date);

    updateMealRecipeRelation(Date, recipe.rname);

    foreach(Ingredient i,recipe.ingredients.toList())
    {
        updateRecipeIngredientRelation(recipe.getName(),i.getName());
    }

    //commented out the code below so it compiles 11/12/2015 -cj

   // foreach(QString step, recipe.steps)
   // {
   //     q.prepare("INSERT INTO steps(rId, step) "
   //               "VALUES (:id, :step);");
   //     qDebug() << "Add step " << step;
   //     q.bindValue(":id",tempRecipeId.toInt());
   //     q.bindValue(":step",step);
   //     q.exec();
   //     qDebug() << q.lastError();
    //    qDebug() << q.lastQuery();
   // }

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

    qDebug() << "inserting: " << ingredient.name;

   // QSqlQuery q = QSqlQuery(db);


    q.prepare("INSERT INTO ingredients(iname, cal, carbs, fat, protein) "
              "VALUES (:iname, :cal, :carbs, :fat, :protein)");

    //q.bindValue(":ingid", ingredient.id);
    q.bindValue(":iname", ingredient.name);
    q.bindValue(":cal", ingredient.getCalories());
    q.bindValue(":carbs", ingredient.getCarbs());
    q.bindValue(":fat", ingredient.getFat());
    q.bindValue(":protein", ingredient.getProtein());
    q.exec();

}

void MpDatabase::addMeal(const QString &date)
{
    q.prepare("insert into meals (mdate) values (:date);");

    q.bindValue(":date", date);

    if(!q.exec())
    {

        qDebug() << q.lastError();

    }

}

//------------------------------------------------------------
//---------retriving from database using relational table
//-------------------------------------------------------------

QVector<QString> MpDatabase::getRecipesByIngredient(const QString &ing){

    //QSqlQuery q = QSqlQuery(db); //this seems kind of reptitive us a macro?

    QVector<QString> tempQueryResult;

    //maybe considering on using joins

    q.prepare("select rname from recipes where recid in "
              "(select rIdRelate from relate where iIdRelate in "
              "(select ingid from ingredients where iname = :ing));"); //rewrite the query using IN

    q.bindValue(":ing", ing);

    if(!q.exec())
    {
        qDebug() << "getRecipesByIngredient: " << q.lastError();
    }

    while(q.next())
    {
        tempQueryResult.append(q.value(0).toString());
    }

    return tempQueryResult;

}


//gets a list of ingredient name based on the recipe name
QVector<QString> MpDatabase::getIngredientsByRecipe(const QString &tempRecipeName)
{
    QVector<QString> tempQueryResult;

    q.prepare("select iname from ingredients where ingid in "
              "(select iIdRelate from relate where rIdRelate in "
              "(select recid from recipes where rname = :name));"); //rewrite the query using IN

    q.bindValue(":name", tempRecipeName);

    if(!q.exec())
    {
        qDebug() << "getIngredientsByRecipe: " << q.lastError();
    }

    while(q.next())
    {
        tempQueryResult.append(q.value(0).toString());
    }

    return tempQueryResult;
}

//maybe consider returning an object of recipe
QVector<Recipe> MpDatabase::getRecipeByDate(const QString &date)
{
   // QSqlQuery q = QSqlQuery(db);

    QVector<QString> tempName;
    QVector<Recipe> tempRecipe;

    q.prepare("select rname from recipes where recid in "
              "(select dnrrid from dateRecipeRelate where dnrmid in "
              "(select mid from meals where mdate = :date));");

    q.bindValue(":date", date);

    if(!q.exec())
    {
        qDebug() << "getRecipeByDate: " << q.lastError();
    }

    while(q.next())
    {
        tempName.append(q.value(0).toString());
    }
    QVectorIterator<QString> tempNameIterator(tempName);

    while(tempNameIterator.hasNext())
    {
        tempRecipe.push_back(getRecipeByName(tempNameIterator.next()));
    }


    return tempRecipe;

}

//---------------------------------------------------------------
//----------updates for relational table
//----------------------------------------------------------------

void MpDatabase::updateRecipeIngredientRelation(const QString &recipeName, const QString &ingredientName){

    //for each ingredient id associated with the new recipe, relate those ingredients with the newly inserted recipe id

    //can we use one QSqlQuery object to do multiple queries or should we use multiple QSqlQuery

    int recid = getRecipeIDByName(recipeName);
    int ingid = getIngredientIDByName(ingredientName);

    q.prepare("insert into relate (rIdRelate, iIdRelate) values (:rId, :iId);");
    q.bindValue(":rId", recid);
    q.bindValue(":iId", ingid);

    if(!q.exec())
    {
        qDebug() << "updateRecipeIngredientRelation: " << q.lastError();
    }

}

void MpDatabase::updateMealRecipeRelation(const QString &date, const QString &recipeName)
{
    int recid = getRecipeIDByName(recipeName);
    int mid = getMealIDByDate(date);

    qDebug() << recipeName << " " << date;
    qDebug() << recid << " " << mid;


    q.prepare("insert into dateRecipeRelate (dnrmid, dnrrid) values (:mid, :rid);");
    q.bindValue(":mid", mid);
    q.bindValue(":rid", recid);


    if(!q.exec())
    {
        qDebug() << "updateMealRecipeRelation: " << q.lastError();
    }


}

//-------------------------------------------------------------------
//-----------finding id's from names or date
//-------------------------------------------------------------------

int MpDatabase::getIngredientIDByName(const QString &ingredient) {
   // QSqlQuery q;
    q.prepare("SELECT ingid FROM ingredients WHERE iname = :name;");
    q.bindValue(":name",ingredient);
    q.exec();
    q.next();
    return q.value(0).toInt();
}

int MpDatabase::getRecipeIDByName(const QString &recipe) {
   // QSqlQuery q;
    q.prepare("SELECT recid FROM recipes WHERE rname = :name;");
    q.bindValue(":name",recipe);
    q.exec();
    q.next();
    return q.value(0).toInt();
}

int MpDatabase::getMealIDByDate(const QString &date)
{

    q.prepare("select mid from meals where mdate = :date;");

    q.bindValue(":date", date);

    if(!q.exec())
    {
        qDebug() << "getMealByDate: " << q.lastError();
    }

    q.next();

    qDebug() << "meal id: " << q.value(0).toInt();

    return q.value(0).toInt();
}
