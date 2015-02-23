#include "ignsql.h"

ignsql::ignsql(QObject *parent) :
    QObject(parent)
{
}

bool ignsql::driver(const QString &drv, QString connect){
    if(drv == "mysql"){
        QStringList con = connect.split(":");
        this->db = QSqlDatabase::addDatabase("QMYSQL");
        this->db.setHostName(con.value(0));
        this->db.setUserName(con.value(1));
        this->db.setPassword(con.value(2));
        this->db.setDatabaseName(con.value(3));
        return this->db.open();
    }
    else if (drv == "sqlite2"){
        this->db = QSqlDatabase::addDatabase("QSQLITE2");
        this->db.setDatabaseName(connect);
        return this->db.open();
    }
    else if (drv == "sqlite"){
        this->db = QSqlDatabase::addDatabase("QSQLITE");
        this->db.setDatabaseName(connect);
        return this->db.open();
    }

}

QVariant ignsql::query(const QString &qr){
    bool status;
    int size;
    QVariantList datarec;
    QVariantMap map;
    QVariantMap contentmap;
    QSqlQuery qry(this->db);

    qry.prepare(qr);
    if(qry.exec()){
        status = true;
    }
    else{
        status = false;
        contentmap.insert("error",qry.lastError().text());
    }

    contentmap.insert("status",status);

    QSqlRecord data = qry.record();

    while (qry.next()) {
        for(int index = 0; index < data.count(); index++) {
            QString key = data.fieldName(index);
            QVariant value = qry.value(index);
            map.insert(key, value);
        }
        datarec << map;
    }

    contentmap.insert("content",datarec);

    if(qry.size() > 0){
        size = qry.size();
        contentmap.insert("size",size);
    }

    QJsonDocument json_enc = QJsonDocument::fromVariant(contentmap);
    return json_enc.toVariant();
}

