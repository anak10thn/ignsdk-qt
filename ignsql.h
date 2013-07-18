#ifndef SQL_H
#define SQL_H

#include <QObject>
#include <QtSql>

class ignsql : public QObject
{
    Q_OBJECT
public:
    explicit ignsql(QObject *parent = 0);
    
signals:
    
public slots:
    void driver(const QString& drv, QString connect);
    //QString query(const QString& qr);
};

#endif // SQL_H
