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
#include "ign.h"
#include <iostream>
using namespace std;
ign::ign(QObject *parent)
    : QObject(parent)
{
    frame = web.page()->mainFrame();
    connect(frame,SIGNAL(javaScriptWindowObjectCleared()), SLOT(ignJS()));

    /*QFile jqueryfile;
    QDir::setCurrent("/usr/share/ign-sdk");
    jqueryfile.setFileName("js/jquery.js");
    QString jquery;
    //jqueryfile.setFileName("qrc:/js/jquery.js");
    if(jqueryfile.open(QIODevice::ReadOnly)){
        jquery = jqueryfile.readAll();
        frame->evaluateJavaScript(jquery);
    }
    else{
        QMessageBox::information(0, "Information","gagal");
    }
    jqueryfile.close();

    frame->evaluateJavaScript("$('head').append('<script src=\"qrc:///js/jquery.js\"></script>')");
    */
    web.settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    web.settings()->setAttribute(QWebSettings::LocalStorageEnabled, true);
    web.settings()->setAttribute(QWebSettings::OfflineStorageDatabaseEnabled, true);
    web.settings()->setAttribute(QWebSettings::OfflineWebApplicationCacheEnabled, true);
    web.settings()->setAttribute(QWebSettings::JavascriptEnabled,true);
    web.settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows,true);
    web.settings()->setAttribute(QWebSettings::JavascriptCanAccessClipboard,true);
    web.settings()->setAttribute(QWebSettings::JavaEnabled,true);
    web.settings()->setAttribute(QWebSettings::WebGLEnabled,true);
    web.settings()->setLocalStoragePath("file://~/.ignsdk");
    web.settings()->setUserStyleSheetUrl(QUrl("file:///usr/share/ign-sdk/css/ign.css"));
    web.page()->action(QWebPage::Reload)->setVisible(false);

    fullscreen = false;

}

void ign::ignJS(){
    this->frame->addToJavaScriptWindowObject("ign",this);
}

void ign::GetFullScreen(){
    if(this->fullscreen){
        this->web.showNormal();
        this->fullscreen = false;
    }
    else{
        this->web.showFullScreen();
        this->fullscreen = true;
    }
}

void ign::render(QString w){
    this->web.load(QUrl(w));
}

void ign::show(){
    this->web.show();
}

void ign::showMaximized(){
    this->web.showMaximized();
}

void ign::showMinimized(){
    this->web.showMinimized();
}

void ign::showMessage(const QString &msg)
{
    QMessageBox::information(0, "Information", msg);
}

void ign::quit(){
    this->web.close();
}

void ign::Back(){
    this->web.page()->action(QWebPage::Back)->isEnabled();
}

void ign::Forward(){
    this->web.page()->action(QWebPage::Forward)->setVisible(true);
}

void ign::stop(){
    this->web.page()->action(QWebPage::Stop)->setVisible(true);
}

void ign::reload(){
    this->web.page()->action(QWebPage::Reload)->setVisible(true);
}

void ign::setDev(bool v){
    this->web.settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, v);
}

void ign::WidgetSizeMax(int w, int h){
    this->web.setMaximumSize(w,h);
}

void ign::WidgetSizeMin(int w, int h){
    this->web.setMinimumSize(w,h);
}
