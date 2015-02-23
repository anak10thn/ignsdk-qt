//ibnu.yahya@toroo.org
#include "igndownload.h"
#include <QCoreApplication>
#include <QUrl>
#include <QtNetwork/QNetworkRequest>
#include <QFile>
#include <QDebug>
#include <QDir>

QtDownload::QtDownload() : QObject(0) {
    QObject::connect(&manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(downloadFinished(QNetworkReply*)));
}

QtDownload::~QtDownload() {

}


void QtDownload::setTarget(const QString &t) {
    this->target = t;
}

void QtDownload::save(const QString &s) {
    this->saveto = s;
}

void QtDownload::downloadFinished(QNetworkReply *data) {
    QUrl file = this->target;
    QFileInfo fileInfo(file.path());
    QString fileName = fileInfo.fileName();
    QString home = this->saveto;
    home += "/"+fileName;
    QFile localFile(home);
    if (!localFile.open(QIODevice::WriteOnly))
        return;
    const QByteArray sdata = data->readAll();
    localFile.write(sdata);
    //qDebug() << sdata;
    localFile.close();

    emit done();
}

void QtDownload::download() {
    QUrl url = QUrl::fromEncoded(this->target.toLocal8Bit());
    QNetworkRequest request(url);
    QObject::connect(manager.get(request), SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(downloadProgress(qint64,qint64)));
    //manager.get(request)->;
}

void QtDownload::downloadProgress(qint64 recieved, qint64 total) {
    //qDebug() << recieved << total;
    emit download_signal(recieved,total);
}
