//ibnu.yahya@toroo.org
#include "ign.h"
#include <iostream>
using namespace std;
ign::ign(QObject *parent)
    : QObject(parent)
{
    frame = web.page()->mainFrame();
    connect(frame,SIGNAL(javaScriptWindowObjectCleared()), SLOT(ignJS()));
    //connect(frame, SIGNAL(titleChanged(const QString&)), SLOT(setWindowTitle(const QString&)));
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
    //set fullscrean mode default to false
    fullscreen = false;

    //web.setWindowOpacity(0.1);
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

void ign::WidgetNoFrame(){
    this->web.setWindowFlags(Qt::FramelessWindowHint);
}

void ign::WidgetTransparent(){
    QPalette pal = this->web.palette();
    pal.setBrush(QPalette::Base, Qt::transparent);
    this->web.setPalette(pal);
    this->web.setAttribute(Qt::WA_OpaquePaintEvent, false);
    this->web.setAttribute(Qt::WA_TranslucentBackground, true);
}

