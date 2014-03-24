#include "ignnetwork.h"

ignnetwork::ignnetwork(QObject *parent):
    QObject(parent)
{
}

QString ignnetwork::myIp(){
    return "yes";
}
