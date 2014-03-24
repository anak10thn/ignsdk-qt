#include "ignnetwork.h"

ignnetwork::ignnetwork(QObject *parent):
    QObject(parent)
{
}

QString ignnetwork::myIP(){
    QString host;
    Q_FOREACH(QHostAddress address, QNetworkInterface::allAddresses()) {
      if (!address.isLoopback() && (address.protocol() == QAbstractSocket::IPv4Protocol)) {
         host = address.toString();
         break;
       }
    }

    if(host.isEmpty()){
        return "IP not found";
    }
    else{
        return host;
    }
}
