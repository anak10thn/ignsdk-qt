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

void ignnetwork::setProxy(const QVariant &config){
    /* json parsing */
    QJsonParseError *err = new QJsonParseError();
    QJsonDocument json = QJsonDocument::fromVariant(config);

    if (err->error != 0) {
      qDebug() << err->errorString();
      exit (1);
    }

    QJsonObject jObject = json.object();
    QVariantMap set_proxy = jObject.toVariantMap();

    if(set_proxy["type"].toString() != ""){
        QNetworkProxy proxy;
        QString proxy_type = set_proxy["type"].toString();
        if(proxy_type == "http"){
            proxy.setType(QNetworkProxy::HttpProxy);
        }
        else if(proxy_type == "socks5"){
            proxy.setType(QNetworkProxy::Socks5Proxy);
        }
        else if(proxy_type == "ftp"){
            proxy.setType(QNetworkProxy::FtpCachingProxy);
        }
        else if(proxy_type == "httpCaching"){
            proxy.setType(QNetworkProxy::HttpCachingProxy);
        }
        else{
            qDebug()<<"Proxy type is not specified. Available options: http, socks5, ftp, httpCaching.";
        }

        if(set_proxy["url"].toString() != ""){
            QString url = set_proxy["url"].toString();
            QStringList url_proxy = url.split(":");
            proxy.setHostName(url_proxy.at(0));
            proxy.setPort(url_proxy.at(1).toInt());
        }
        else{
            qDebug()<<"Proxy address is not specified.";
        }

        if(set_proxy["username"].toString() != ""){
            proxy.setUser(set_proxy["username"].toString());
        }

        if(set_proxy["password"].toString() != ""){
            proxy.setPassword(set_proxy["password"].toString());
        }

        QNetworkProxy::setApplicationProxy(proxy);
    }
}

QString ignnetwork::get(const QString &url){
    QEventLoop eventLoop;
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    QUrl uri(url);
    QNetworkRequest req(uri);
    QNetworkReply *reply = mgr.get(req);
    eventLoop.exec();
    if(reply->error() == QNetworkReply::NoError){
        return reply->readAll();
        delete reply;
    }
    else{
        return reply->errorString();
        delete reply;
    }
}
