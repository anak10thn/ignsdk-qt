#ifndef IGNSERIAL_H
#define IGNSERIAL_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTextStream>
#include <QList>
#include "ignjson.h"

class ignserial : public QObject
{
    Q_OBJECT
public:
    explicit ignserial(QObject *parent = 0);
    ignjson *json;

public slots:
    QVariant info();
};

#endif // IGNSERIAL_H
