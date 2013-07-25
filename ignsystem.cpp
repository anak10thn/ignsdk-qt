#include "ignsystem.h"
#include <QDebug>

ignsystem::ignsystem(QObject *parent) :
    QObject(parent)
{

}

void ignsystem::tes(){
    qDebug() << "tes";
}
