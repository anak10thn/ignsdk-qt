#ifndef IGN_H
#define IGN_H

#include <QtGui/QMainWindow>
#include <QtWebKit/QWebView>
#include <QObject>
#include <QMessageBox>
#include <QtWebKit/QWebFrame>
#include <QProcess>
#include <QtWebKit/QWebSettings>
class ign: public QObject
{
    Q_OBJECT
private:
    QWebView web;
public:
    ign(QObject *parent = 0);
    void render(QString w);
    void show();
public slots:
    void showMessage(const QString& msg);
    void setDev(bool v);
    void quit();
    void back();
    void forward();
    void reload();
    void stop();
};

#endif // IGN_H
