#include <QObject>
#include <QString>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>


class QtDownload : public QObject {
    Q_OBJECT
public:
    explicit QtDownload();
    ~QtDownload();

    void setTarget(const QString& t);

private:
    QNetworkAccessManager manager;
    QString target;


signals:
    void done();
    void pst(qint64 recieved, qint64 total);
public slots:
    void download();
    void downloadFinished(QNetworkReply* data);
    void downloadProgress(qint64 recieved, qint64 total);
};
