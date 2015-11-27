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

   //create meals table

   q.exec("create table meals(mid integer primary key, mdate text unique);");

   //create recipe table

   q.exec("create table recipes(recid integer primary key, rname text unique, steps text);");

   //create ingredients table

   q.exec("create table ingredients(ingid integer primary key, iname text unique,"
        "cal int, carbs int, fat int, protein int);");


   //create relation table for recipe and ingredient

   q.exec("create table relate (rIdRelate int, iIdRelate int, "
         "foreign key (rIdRelate) references recipes(recid), "
         "foreign key (iIdRelate) references ingredients(ingid));");

   //create relation table for recipe and date

   q.exec("create table dateRecipeRelate (dnrmid int, dnrrid int, "
         "foreign key (dnrmid) references meals(mid),"
         "foreign key (dnrrid) references recipes(recid));");

   /*
   q.exec("create table steps (rId int, step text, "
         "foreign key (rId) references recipes(recid));");
         */

}

MpDatabase& MpDatabase::GetDBInstance()
{
   static MpDatabase DB;
   return DB;
}

Ingredient MpDatabase::getIngredientByName(const QString &name)
{

    //request goes to the database, which returns an ingredient object with all the information

    //preparing the query statements

   q.prepare("SELECT * FROM ingredients WHERE iname = :n");
   q.bindValue(":n",name);
   q.exec();
   q.next();

   Ingredient i(q.value(5).toInt(),q.value(4).toInt(),q.value(3).toInt(),q.value(2).toInt(),q.value(1).toString());

   return i;
}

Recipe MpDatabase::getRecipeByName(const QString &name)
{

    //request goes to the database, which returns a recipe object with all the information on the recipe, includeing the ingredient

   q.prepare("SELECT recid, rname, steps FROM recipes WHERE rname = :n");
   q.bindValue(":n",name);
   q.exec();
   q.next();

   QString tempSteps = q.value(2).toString();

   QString tempName = q.value(1).toString();

   QVector<QString> IngNames = getIngredientsByRecipe(name);

   QVector<Ingredient> Ings;

   foreach(QString s, IngNames.toList())
   {
      Ings.push_back(getIngredientByName(s));
   }

   Recipe r(Ings, tempSteps, tempName);

   return r;
}

QVector<QString> MpDatabase::getRecipeNames()
{

   //returns a vector of recipe names from the database

   QVector<QString> names;

   q.exec("SELECT rname FROM recipes;");

   while(q.next())
   {
      names.append(q.value(0).toString());
   }

   return names;
}

QVector<QString> MpDatabase::getIngredientNames()
{
   //returns a vector of ingredients name from the database

   QVector<QString> names;

   q.exec("SELECT iname FROM ingredients;");

   while(q.next())
   {
      names.append(q.value(0).toString());
   }
   return names;
}

QVector<Recipe> MpDatabase::getAllRecipe()
{
   //returns all the recipe objects from the database

   QVector<QString> tempName(getRecipeNames()); //gets the name of the recipes and puts them into a vector

   QVectorIterator<QString> tempNameIterator(tempName);

   QVector<Recipe> tempRecipe;

   while(tempNameIterator.hasNext())
   {
       //the tempName vector gets iterated through and adds the entire recipe object into a vector of recipes

      tempRecipe.append(getRecipeByName(tempNameIterator.next()));
   }

   return tempRecipe;
}

//-----------------------------------------------
//-------adding into the database
//-----------------------------------------------


void MpDatabase::addRecipe(const Recipe &recipe, const QString Date)
{

    //adds the new recipe object into the database along with the date it is associated with

    //preparing the query statements

    q.prepare("INSERT INTO recipes(rname, steps)"
              "VALUES (:name, :steps)");
    q.bindValue(":name", recipe.getName()); //name is private
    q.bindValue(":steps", recipe.GetDirections());

    if(!q.exec())
    {
        qDebug() << "addRecipe: " << q.lastError();
    }

    addMeal(Date); //adds the date to the meal's table in the database

    updateMealRecipeRelation(Date, recipe.RecipeName); //updates the recipe and date relationship in the database

    foreach(Ingredient i,recipe.IngredientsList.toList())
    {       
        updateRecipeIngredientRelation(recipe.getName(),i.getName()); //updates the recipe and ingredient relationship in the database
    }

}

void MpDatabase::addIngredient(const Ingredient &ingredient)
{

    //adds the ingredient information into the database

    //preparing the query statements

    q.prepare("INSERT INTO ingredients(iname, cal, carbs, fat, protein) "
              "VALUES (:iname, :cal, :carbs, :fat, :protein)");

    q.bindValue(":iname", ingredient.getName());
    q.bindValue(":cal", ingredient.getCalories());
    q.bindValue(":carbs", ingredient.getCarbs());
    q.bindValue(":fat", ingredient.getFat());
    q.bindValue(":protein", ingredient.getProtein());

    q.exec();
}

void MpDatabase::addMeal(const QString &date)
{
    //adds the date into the database

    //preparing the query statements

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

QVector<QString> MpDatabase::getRecipesByIngredient(const QString &ing)
{
    //returns the all the recipe names based on the ingredients

   QVector<QString> tempQueryResult;

   //preparing the query statements

   q.prepare("select rname from recipes where recid in "
         "(select rIdRelate from relate where iIdRelate in "
         "(select ingid from ingredients where iname = :ing));");

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



QVector<QString> MpDatabase::getIngredientsByRecipe(const QString &tempRecipeName)
{

    //gets a list of ingredient name based on the recipe name

   QVector<QString> tempQueryResult;

   //preparing the query statements

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

QVector<Recipe> MpDatabase::getRecipeByDate(const QString &date)
{
   //returns a vector of recipe objects based on the date

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
      //as the vector recipe gets iterated and passed into the getRecipeByName function

      //returning recipe objects gets pushed in to the recipe vector

      tempRecipe.push_back(getRecipeByName(tempNameIterator.next()));
   }

   return tempRecipe;

}

//---------------------------------------------------------------
//----------updates for relational table
//----------------------------------------------------------------

void MpDatabase::updateRecipeIngredientRelation(const QString &recipeName, const QString &ingredientName)
{
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

int MpDatabase::getIngredientIDByName(const QString &ingredient)
{
   q.prepare("SELECT ingid FROM ingredients WHERE iname = :name;");

   q.bindValue(":name",ingredient);

   q.exec();

   q.next();

   return q.value(0).toInt();
}

int MpDatabase::getRecipeIDByName(const QString &recipe)
{
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
