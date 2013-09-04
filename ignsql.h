#ifndef SQL_H
#define SQL_H

#include <QObject>
#include <QtSql>
#include <qjson/parser.h>
#include <qjson/parserrunnable.h>
#include <qjson/serializer.h>
#include <qjson/serializerrunnable.h>
#include <qjson/qjson_export.h>
#include <qjson/qobjecthelper.h>

class ignsql : public QObject
{
    Q_OBJECT
public:
    explicit ignsql(QObject *parent = 0);
    //QSqlQuery qry;
    QSqlDatabase db;
signals:
    void record(bool err,const QByteArray& data);
public slots:
    bool driver(const QString& drv, QString connect);
    void query(const QString& qr);
};

#endif // SQL_H
