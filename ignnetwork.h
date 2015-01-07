#ifndef IGNNETWORK_H
#define IGNNETWORK_H

#include <QObject>
#include <QNetworkInterface>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>
#include <QNetworkProxy>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QEventLoop>

class ignnetwork : public QObject
{
    Q_OBJECT
public:
    explicit ignnetwork(QObject *parent = 0);
public slots:
    QString myIP();
    void setProxy(const QVariant &config);
    QString get(const QString &url);
};

#endif // IGNNETWORK_H
