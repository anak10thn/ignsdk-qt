#include "ignsql.h"

ignsql::ignsql(QObject *parent) :
    QObject(parent)
{
}

void ignsql::driver(const QString &drv, QString connect){
    if(drv == "mysql"){
        QStringList con = connect.split(":");
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName(con.value(0));
        db.setUserName(con.value(1));
        db.setPassword(con.value(2));
        db.setDatabaseName(con.value(3));
        if(!db.open()){
            qDebug() << db.lastError();
            qFatal("Gagal melakukan koneksi.");
        }
        else {
            qDebug() << "database connect";
        }
    }
    else if (drv == "sqlite"){
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(connect);
        if(!db.open()){
            qDebug() << db.lastError();
            qFatal("Gagal melakukan koneksi.");
        }
        else {
            qDebug() << "database connect";
        }
    }
    else if (drv == "sqlite3"){
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE3");
        db.setDatabaseName(connect);
        if(!db.open()){
            qDebug() << db.lastError();
            qFatal("Gagal melakukan koneksi.");
        }
        else {
            qDebug() << "database connect";
        }
    }

}
