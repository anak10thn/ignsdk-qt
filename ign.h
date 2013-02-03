#ifndef IGN_H
#define IGN_H

#include <QtGui/QMainWindow>
#include <QtWebKit/QWebView>
#include <QObject>
#include <QMessageBox>
#include <QtWebKit/QWebFrame>

class ign: public QObject
{
    Q_OBJECT
public:
    ign(QObject *parent = 0);
public slots:
    void showMessage(const QString& msg);
    QString quit();
signals:
    void quitRequested();
};

#endif // IGN_H
