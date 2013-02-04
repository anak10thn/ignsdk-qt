#include "ign.h"
#include <iostream>
using namespace std;
ign::ign(QObject *parent)
    : QObject(parent)
{
    QWebFrame *frame = web.page()->mainFrame();
    frame->addToJavaScriptWindowObject("ign",this);
    web.settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    web.settings()->setAttribute(QWebSettings::LocalStorageEnabled, true);
    web.settings()->setAttribute(QWebSettings::OfflineStorageDatabaseEnabled, true);
    web.settings()->setAttribute(QWebSettings::OfflineWebApplicationCacheEnabled, true);
}

void ign::render(QString w){
    this->web.load(QUrl(w));
}

void ign::show(){
    this->web.show();
}

void ign::showMessage(const QString &msg)
{
    QMessageBox::information(0, "Information", msg);
}

void ign::quit(){
    this->web.close();
}

void ign::back(){
    this->web.back();
}

void ign::forward(){
    this->web.forward();
}

void ign::stop(){
    this->web.stop();
}

void ign::reload(){
    this->web.reload();
}

void ign::setDev(bool v){
    this->web.settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, v);
}
