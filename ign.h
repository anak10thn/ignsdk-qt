#ifndef IGN_H
#define IGN_H

#include <QtGui/QMainWindow>
#include <QtWebKit/QWebView>
#include <QObject>
#include <QMessageBox>
#include <QtWebKit/QWebFrame>
#include <QProcess>
class ign: public QObject
{
    Q_OBJECT
private:
    QWebView web;
public:
    ign(QObject *parent = 0);
    void render(QUrl w);
    void show();
public slots:
    void showMessage(const QString& msg);
    void quit();
};

#endif // IGN_H
