#ifndef ADMINDB_H
#define ADMINDB_H
#include <QtSql>
#include <QString>

class AdminDB
{

private:
    //make the constructor private so that this class cannot be
    //instantiated
    AdminDB() {}
    AdminDB(const AdminDB &);
    ~AdminDB() {}
     static AdminDB * instance; //declaration of static member!
     QSqlDatabase db; //declaration of static member!
     bool flag_db;

public:

    static AdminDB * getInstance(){
        if ( instance  == 0 ) {
            instance  = new AdminDB();
        }
        return instance;
    }

    bool executeQuery(QString query){
        QSqlQuery * qry = new QSqlQuery();
        qry->prepare( query );
          if( !qry->exec() )
            return false;
          else
            return true;
    }

    bool connectDB()
    {
        if(!flag_db){
            db = QSqlDatabase::addDatabase("QMYSQL");

            db.setHostName("localhost");
            db.setDatabaseName("mydb");
            db.setUserName("maxi");
            db.setPassword("pc");

            flag_db = db.open();
            return flag_db;
        }
        return false;

    }

    void disconnectDB()
    {
        if(flag_db){
            QString sDBName = db.connectionName();
            db.close();
            QSqlDatabase::removeDatabase(sDBName);
        }
    }

};

#endif // ADMINDB_H

