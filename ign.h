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
#include <QVariant>

class ign: public QObject
{
    Q_OBJECT
private:
    QWebView web;
    QWebFrame *frame;
    bool fullscreen;

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
    void showMessage(const QString& msg);
    void setDev(bool v);
    void quit();
    void Back();
    void Forward();
    void Reload();
    void Stop();
    void WidgetSizeMax(int w,int h);
    void WidgetSizeMin(int w,int h);
    void getToggleFullScreen();
    void getFullScreen(bool screen);
    void showMaximized();
    void showMinimized();
    QString cliOut(const QString& cli);
    void config(QString path);
};

#endif // IGN_H
