#ifndef IGN_H
#define IGN_H

#include <QtGui/QMainWindow>
#include <QWidget>
#include <QLayout>
#include <QtWebKit/QWebView>
#include <QObject>
#include <QMessageBox>
#include <QtWebKit/QWebFrame>
#include <QProcess>
#include <QtWebKit/QWebSettings>
#include <QSize>
#include <QtGui>
class ign: public QObject
{
    Q_OBJECT
private:
    QWebView web;
    QWebFrame *frame;
public:
    ign(QObject *parent = 0);
    void render(QString w);
    void show();
public slots:
    void showMessage(const QString& msg);
    void setDev(bool v);
    void quit();
    void Back();
    void Forward();
    void reload();
    void stop();
    void WidgetSizeMax(int w,int h);
    void WidgetSizeMin(int w,int h);
    void ignJS();
};

#endif // IGN_H
