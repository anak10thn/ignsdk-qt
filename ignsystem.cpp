#include "ignsystem.h"
#include <QDebug>

ignsystem::ignsystem(QObject *parent)
    : QObject(parent)
{

}

QString ignsystem::cliOut(const QString& cli){
    QProcess os;
    os.start(cli);
    int pid = os.pid();
    qDebug() << pid;
    os.waitForFinished(-1);
    return os.readAllStandardOutput();
}

void ignsystem::exec(const QString &cli){
    QProcess os;
    os.startDetached("/bin/sh -c \""+cli+"\"");
}
