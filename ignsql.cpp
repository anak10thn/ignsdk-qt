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
    else if (drv == "sqlite"){
        this->db = QSqlDatabase::addDatabase("QSQLITE");
        this->db.setDatabaseName(connect);
        return this->db.open();
    }
    else if (drv == "sqlite3"){
        this->db = QSqlDatabase::addDatabase("QSQLITE3");
        this->db.setDatabaseName(connect);
        return this->db.open();
    }

}

void ignsql::query(const QString &qr){
    QSqlQuery qry(this->db);
    qry.prepare(qr);
    qry.exec();

    QSqlRecord data = qry.record();
    QVariantList datarec;
    QVariantMap map;

    for(int index = 0; index < data.count(); ++index) {
        QString key = data.fieldName(index);
        QVariant value = data.value(index);

        map.insert(key, value);
    }

    datarec << map;

    QJson::Serializer serializer;
    bool ok;
    QByteArray json = serializer.serialize(datarec, &ok);

    if (ok) {
      emit record(ok,json);
    }
}
