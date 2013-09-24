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
    //void record_sig(bool err,const QByteArray& data);
    //void record(bool err,const QByteArray& data);
public slots:
    bool driver(const QString& drv, QString connect);
    QString query(const QString& qr);
    //void record_slot(bool err,const QByteArray& data);
};

#endif // SQL_H
