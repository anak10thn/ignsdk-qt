//ibnu.yahya@toroo.org
#ifndef IGN_H
#define IGN_H
#include "fs.h"
#include "igndownload.h"
#include "ignsql.h"
#include "ignsystem.h"
#include <QObject>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLayout>
#include <QtWidgets/QMessageBox>
#include <QtWebKitWidgets/QtWebKitWidgets>
#include <QtNetwork/QNetworkInterface>
#include <QSize>
#include <QVariant>
#include <QPixmap>
#include <QtWidgets/QSplashScreen>
#include <QTimer>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>
#include <QNetworkProxy>

class ign: public QObject
{
    Q_OBJECT
private:
    QWebView web;
    QWebFrame *frame;
    bool fullscreen;
    fs *m_filesystem;
    QtDownload *dl;
    ignsql *m_sqldrv;
    ignsystem *m_ignsystem;
    QPoint offset;
    bool mMoving;
public:
    ign(QObject *parent = 0);
    void render(QString w);
    void show();
    void widgetNoFrame();
    void widgetTransparent();
    QString pathApp;
    QString version;

signals:
    void downloadProgress(qint64 recieved, qint64 total);
    /*void bash(QString out, QString err);*/
public slots:
    //main slot
    void ignJS();
    void setUrl(const QString& url);
    //ign message
    void showMessage(const QString& msg);
    //ign developer mode
    void setDev(bool v);
    void setDevRemote(int port);
    //ign action
    void quit();
    void back();
    void forward();
    void reload();
    void stop();
    void cut();
    void copy();
    void paste();
    void undo();
    void redo();
    //ign window function
    void widgetSizeMax(int w,int h);
    void widgetSizeMin(int w,int h);
    void widgetSize(int w,int h);
    void widgetNoTaskbar();
    void getToggleFullScreen();
    void getFullScreen(bool screen);
    void showMaximized();
    void showMinimized();
    //ign load external binary
    QString loadBin(const QString &script);
    //ign manifest
    void config(QString path);
    //ign settings
    void websecurity(bool c);
    //ign filesystem
    QObject *filesystem();
    //ign network
    void saveFile(const QByteArray &data, QString filename, QString path);
    void download(QString data, QString path);
    void download_signal(qint64 recieved, qint64 total);
    //ign sql
    QObject *sql();
    //experiment
    QObject *sys();
    //ignsdk version
    QString sdkVersion();
};

#endif // IGN_H
