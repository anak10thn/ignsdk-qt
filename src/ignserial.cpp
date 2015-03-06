#include "ignserial.h"

ignserial::ignserial(QObject *parent) : QObject(parent){}

QVariant ignserial::info(){
    QList<QSerialPortInfo> serialPortList = QSerialPortInfo::availablePorts();
    const QString blank = QString::null;
    QString desc,manufacturer,serialNumber;
    bool busy;
    QVariantMap out,info;
    QVariantList list;

    out.insert("count",serialPortList.count());

    if(serialPortList.count() > 0){
        foreach (const QSerialPortInfo &serial, serialPortList) {
            desc = (!serial.description().isEmpty() ? serial.description() : blank);
            manufacturer = (!serial.manufacturer().isEmpty() ? serial.manufacturer() : blank);
            serialNumber = (!serial.serialNumber().isEmpty() ? serial.serialNumber() : blank);
            busy = serial.isBusy();
            info.insert("port",serial.portName());
            info.insert("location",serial.systemLocation());
            info.insert("vendor",(serial.hasVendorIdentifier() ? QByteArray::number(serial.hasVendorIdentifier(),16) : blank));
            info.insert("product",(serial.hasProductIdentifier() ? QByteArray::number(serial.hasProductIdentifier(),16) : blank));
            info.insert("isBusy",busy);
            info.insert("description",desc);
            info.insert("manufacturer",manufacturer);
            info.insert("serialNumber",serialNumber);
            list << info;
        }
        out.insert("device",list);
    }

    QJsonDocument json_enc = QJsonDocument::fromVariant(out);
    return json_enc.toVariant();
}
