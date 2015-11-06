#ifndef IGNSERIAL_H
#define IGNSERIAL_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTextStream>
#include <QList>
#include <QTimer>
#include "ignjson.h"

class ignserial : public QObject
{
    Q_OBJECT
public:
    explicit ignserial(QObject *parent = 0);
    ignjson *json;
    QSerialPort read;
    QTimer time;

public slots:
    QVariant info();
    void Read(const QVariant &config);
    void readOut();

signals:
    void out(const QString& out,const QString& err);

};

#endif // IGNSERIAL_H
