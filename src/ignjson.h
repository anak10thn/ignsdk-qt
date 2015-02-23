#ifndef IGNJSON
#define IGNJSON
#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>
#include <QDebug>

class ignjson : public QObject
{
    Q_OBJECT
public:
    explicit ignjson(QObject *parent = 0);
    QJsonObject jsonParser(const QVariant &config){
        /* json parsing */
        QJsonParseError *err = new QJsonParseError();
        QJsonDocument json = QJsonDocument::fromVariant(config);

        if (err->error != 0) {
          qDebug() << err->errorString();
          exit (1);
        }

        return json.object();
    }
};
#endif // IGNJSON

