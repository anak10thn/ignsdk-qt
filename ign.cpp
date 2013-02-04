#include "ign.h"
#include <iostream>
using namespace std;
ign::ign(QObject *parent)
    : QObject(parent)
{
    QFile jqueryfile;
    jqueryfile.setFileName(":/js/jquery.js");
    jqueryfile.open(QIODevice::ReadOnly);
    QString jquery = jqueryfile.readAll();
    jqueryfile.close();

    frame = web.page()->mainFrame();

    connect(frame,SIGNAL(javaScriptWindowObjectCleared()), SLOT(ignJS()));

    frame->evaluateJavaScript(jquery);
    //frame->evaluateJavaScript("var head = document.getElementsByTagName('head')[0];var script = document.createElement('script');script.type = 'text/javascript';script.src = 'qrc:///js/jquery.js';head.appendChild(script);");
    web.settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    web.settings()->setAttribute(QWebSettings::LocalStorageEnabled, true);
    web.settings()->setAttribute(QWebSettings::OfflineStorageDatabaseEnabled, true);
    web.settings()->setAttribute(QWebSettings::OfflineWebApplicationCacheEnabled, true);
    //web.settings()->setAttribute(QWebSettings::JavascriptEnabled,true);
    web.settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows,true);
    web.settings()->setAttribute(QWebSettings::JavascriptCanAccessClipboard,true);
    web.settings()->setAttribute(QWebSettings::JavaEnabled,true);
    web.settings()->setAttribute(QWebSettings::WebGLEnabled,true);
    web.page()->action(QWebPage::Reload)->setVisible(false);

}

void ign::ignJS(){
    this->frame->addToJavaScriptWindowObject("ign",this);
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
