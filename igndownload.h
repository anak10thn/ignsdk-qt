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
    void save(const QString& s);

private:
    QNetworkAccessManager manager;
    QString target;
    QString saveto;


signals:
    void done();
    void download_signal(qint64 recieved, qint64 total);
public slots:
    void download();
    void downloadFinished(QNetworkReply* data);
    void downloadProgress(qint64 recieved, qint64 total);
};
