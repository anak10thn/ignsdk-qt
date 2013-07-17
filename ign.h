//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.
//      by ibnu.yahya@toroo.org
#ifndef IGN_H
#define IGN_H
#include "fs.h"
#include "igndownload.h"
#include <QtGui/QMainWindow>
#include <QWidget>
#include <QLayout>
#include <QObject>
#include <QMessageBox>
#include <QProcess>
#include <QtWebKit>
#include <QSize>
#include <QtGui>
#include <QVariant>
#include <QCryptographicHash>

class ign: public QObject
{
    Q_OBJECT
private:
    QWebView web;
    QWebFrame *frame;
    bool fullscreen;
    fs *filesystem;
    QtDownload *dl;
    QString id;
    QPoint mLastMousePosition;
    bool mMoving;
public:
    ign(QObject *parent = 0);
    void render(QString w);
    void show();
    void WidgetNoFrame();
    void WidgetTransparent();
protected:
    //virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent * event);
    //virtual void mouseReleaseEvent(QMouseEvent *event);

public slots:
    void ignJS();
    //ign message
    void showMessage(const QString& msg);
    //ign developer mode
    void setDev(bool v);
    //ign signal
    void quit();
    void Back();
    void Forward();
    void Reload();
    void Stop();
    //ign window function
    void WidgetSizeMax(int w,int h);
    void WidgetSizeMin(int w,int h);
    void WidgetSize(int w,int h);
    void getToggleFullScreen();
    void getFullScreen(bool screen);
    void showMaximized();
    void showMinimized();
    //ign system
    QString cliOut(const QString& cli);
    //ign manifest
    void config(QString path);
    //ign settings
    void websecurity(bool c);
    //ign filesystem
    QString homePath();
    //ign network
    void saveFile(const QByteArray &data, QString filename, QString path);
    void download(QString data, QString path, QString id);
    void download_signal(qint64 recieved, qint64 total);
    //hash function
    QString hash(const QString& data, QString hash_func);
};

#endif // IGN_H
