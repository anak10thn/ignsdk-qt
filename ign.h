//ibnu.yahya@toroo.org
#ifndef IGN_H
#define IGN_H
#include "fs.h"
#include "igndownload.h"
#include "ignsql.h"
#include "ignsystem.h"
#include <QtGui/QMainWindow>
#include <QtGui/QWidget>
#include <QtGui/QLayout>
#include <QObject>
#include <QtGui/QMessageBox>
#include <QProcess>
#include <QtWebKit>
#include <QtWebKitWidgets/QtWebKitWidgets>
#include <QSize>
#include <QtGui>
#include <QVariant>
#include <QCryptographicHash>
#include <QPixmap>
#include <QtGui/QSplashScreen>
#include <QTimer>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>

class ign: public QObject
{
    Q_OBJECT
private:
    QWebView web;
    QWebFrame *frame;
    bool fullscreen;
    fs *filesystem;
    QtDownload *dl;
    ignsql *m_sqldrv;
    ignsystem *m_ignsystem;
    QPoint mLastMousePosition;
    bool mMoving;
public:
    ign(QObject *parent = 0);
    void render(QString w);
    void show();
    void widgetNoFrame();
    void widgetTransparent();
    QString pathApp;
    QString version;

protected:
    //virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent * event);
    //virtual void mouseReleaseEvent(QMouseEvent *event);

signals:
    void downloadProgress(qint64 recieved, qint64 total);
    /*void bash(QString out, QString err);*/
public slots:
    //main slot
    void ignJS();
    //ign message
    void showMessage(const QString& msg);
    //ign developer mode
    void setDev(bool v);
    //ign signal
    void quit();
    void back();
    void forward();
    void reload();
    void stop();
    //ign window function
    void widgetSizeMax(int w,int h);
    void widgetSizeMin(int w,int h);
    void widgetSize(int w,int h);
    void getToggleFullScreen();
    void getFullScreen(bool screen);
    void showMaximized();
    void showMinimized();
    //ign system
    QString cliOut(const QString& cli);
    void exec(const QString& cli);
    QString loadBin(const QString &script);
    /*void bash(QString out, QString err);*/
    //ign manifest
    void config(QString path);
    //ign settings
    void websecurity(bool c);
    //ign filesystem
    QString homePath();
    bool createFile(const QString& path, const QString& data);
    QString readFile(const QString &path);
    bool mkdir(const QString& path);
    bool dirExist(const QString& path);
    bool fileExist(const QString& path);
    bool fileRemove(const QString& path);
    bool rmdir(const QString& path);
    //ign network
    void saveFile(const QByteArray &data, QString filename, QString path);
    void download(QString data, QString path);
    void download_signal(qint64 recieved, qint64 total);
    //hash function
    QString hash(const QString& data, QString hash_func);
    //ign sql
    QObject *sql();
    //experiment
    QObject *sys();
    //ignsdk version
    QString sdkVersion();
};

#endif // IGN_H
