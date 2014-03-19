//ibnu.yahya@toroo.org

#include "ign.h"
#include "fs.h"
#include "cmath"
#include <QtCore/QVariant>
#include <iostream>
using namespace std;

ign::ign(QObject *parent)
    : QObject(parent),
    m_sqldrv(0),
    m_ignsystem(0),
    m_filesystem(0)
{
    this->version = "1.1.4";
    this->debugging = false;
    frame = web.page()->mainFrame();
    connect(frame,SIGNAL(javaScriptWindowObjectCleared()), SLOT(ignJS()));
    this->dl = new QtDownload;

    QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);
    web.settings()->setAttribute(QWebSettings::PluginsEnabled, true);
    web.settings()->setAttribute(QWebSettings::LocalStorageEnabled, true);
    web.settings()->setAttribute(QWebSettings::OfflineStorageDatabaseEnabled, true);
    web.settings()->setAttribute(QWebSettings::OfflineWebApplicationCacheEnabled, true);
    web.settings()->setAttribute(QWebSettings::JavascriptEnabled,true);
    web.settings()->setAttribute(QWebSettings::JavascriptCanOpenWindows,true);
    web.settings()->setAttribute(QWebSettings::JavascriptCanAccessClipboard,true);
    web.settings()->setAttribute(QWebSettings::JavaEnabled,true);
    web.settings()->setAttribute(QWebSettings::AcceleratedCompositingEnabled,true);
    web.settings()->setAttribute(QWebSettings::WebGLEnabled,true);
    web.settings()->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls,false);
    //webstorage
    QString home = QDir::homePath();
    home += "/.ignsdk";
    web.settings()->setLocalStoragePath(home);
    web.settings()->enablePersistentStorage(home);
    web.settings()->setOfflineWebApplicationCachePath(home);
    //stylesheet default
    web.settings()->setUserStyleSheetUrl(QUrl("qrc:/css/ign.css"));
    //config mode disable
    web.page()->action(QWebPage::Back)->setVisible(false);
    web.page()->action(QWebPage::Forward)->setVisible(false);
    web.page()->action(QWebPage::Reload)->setVisible(false);
    web.page()->action(QWebPage::Stop)->setVisible(false);
    //set fullscrean mode default to false
    fullscreen = false;

    //web.setWindowOpacity(0.1);
}

void ign::ignJS(){
    this->frame->addToJavaScriptWindowObject("ign",this);
}

void ign::render(QString w){
    QString pwd("");
    QString url_fix;
    char * PWD;
    PWD = getenv ("PWD");
    pwd.append(PWD);
    QStringList url_exp = w.split("/");
    if(url_exp.at(0) == "http:" || url_exp.at(0) == "https:"){
        url_fix = w;
    }
    else if(url_exp.at(0) == ".."){
        url_fix = "file://"+pwd+"/"+w;
    }
    else if(url_exp.at(0) == ""){
        url_fix = "file://"+w;
    }
    else {
        url_fix = "file://"+pwd+"/"+w;
    }
    this->web.load(url_fix);
}

void ign::setUrl(const QString &url){
    this->web.setUrl(QUrl(url ));
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

/*action trigger*/
void ign::quit(){
    this->web.close();
}

void ign::back(){
    this->web.page()->triggerAction(QWebPage::Back,true);
}

void ign::forward(){
    this->web.page()->triggerAction(QWebPage::Forward,true);
}

void ign::stop(){
    this->web.page()->triggerAction(QWebPage::Stop,true);
}

void ign::reload(){
    this->web.page()->triggerAction(QWebPage::Reload,true);
}

void ign::cut(){
    this->web.page()->triggerAction(QWebPage::Cut,true);
}

void ign::copy(){
    this->web.page()->triggerAction(QWebPage::Copy,true);
}

void ign::paste(){
    this->web.page()->triggerAction(QWebPage::Paste,true);
}

void ign::undo(){
    this->web.page()->triggerAction(QWebPage::Undo,true);
}

void ign::redo(){
    this->web.page()->triggerAction(QWebPage::Redo,true);
}

/* debuging mode */
void ign::setDev(bool v){
    this->web.settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, v);
    this->debugging = true;
}

void ign::setDevRemote(int port){
    QString host;
    Q_FOREACH(QHostAddress address, QNetworkInterface::allAddresses()) {
      if (!address.isLoopback() && (address.protocol() == QAbstractSocket::IPv4Protocol)) {
         host = address.toString();
         break;
       }
    }
    QString server;
       if (host.isEmpty()) {
          server = QString::number(port);
        } else {
          server = QString("%1:%2").arg(host, QString::number(port));
        }
    qDebug() << "Remote debugging is enable : "<< server.toUtf8();
    qputenv("QTWEBKIT_INSPECTOR_SERVER", server.toUtf8());
    this->web.page()->setProperty("_q_webInspectorServerPort",port);
}

/* web security */
void ign::websecurity(bool c){
    web.settings()->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls,c);
}
/* window config */
void ign::widgetSizeMax(int w, int h){
    this->web.setMaximumSize(w,h);
}

void ign::widgetSizeMin(int w, int h){
    this->web.setMinimumSize(w,h);
}

void ign::widgetSize(int w, int h){
    this->web.resize(w,h);
}

void ign::widgetNoFrame(){
    this->web.setWindowFlags(Qt::FramelessWindowHint);
}

void ign::widgetNoTaskbar(){
    this->web.setWindowFlags(this->web.windowFlags() | Qt::Tool);
}

void ign::widgetTransparent(){
    QPalette pal = this->web.palette();
    pal.setBrush(QPalette::Base, Qt::transparent);
    this->web.setPalette(pal);
    this->web.setAttribute(Qt::WA_OpaquePaintEvent, false);
    this->web.setAttribute(Qt::WA_TranslucentBackground, true);
}

void ign::getToggleFullScreen(){
    if(this->fullscreen){
        this->web.showNormal();
        this->fullscreen = false;
    }
    else{
        this->web.showFullScreen();
        this->fullscreen = true;
    }
}

void ign::getFullScreen(bool screen){
    if(screen){
        this->web.showFullScreen();
        this->fullscreen = true;
    }
    else {
        this->web.showNormal();
        this->fullscreen = false;
    }
}

/*load external binary*/
QString ign::loadBin(const QString &script){
    QStringList list = this->pathApp.split("/");

    QString pwd("");
    char * PWD;
    PWD = getenv ("PWD");
    pwd.append(PWD);

    QString path_bin;
    if(list.at(0) != ""){
        path_bin = pwd+"/"+this->pathApp;
    }
    else{
        path_bin = this->pathApp;
    }
    return path_bin+"/bin/"+script;
}

void ign::config(QString path){
    QFile config_file;
    QDir::setCurrent(path);
    config_file.setFileName("ignsdk.json");
    QByteArray config;
    if(config_file.open(QIODevice::ReadOnly)){
        config = config_file.readAll();

        QJsonParseError *err = new QJsonParseError();

        QJsonDocument ignjson = QJsonDocument::fromJson(config, err);

        if (err->error != 0) {
          qDebug() << err->errorString();
          exit (1);
        }

        QJsonObject jObject = ignjson.object();

        //convert the json object to variantmap
        QVariantMap result = jObject.toVariantMap();

        QVariantMap configure = result["config"].toMap();
        if(configure["debug"].toBool()){
            this->setDev(true);
        }
        if(configure["debug-port"].toInt()){
            this->setDevRemote(configure["debug-port"].toInt());
        }
        if(configure["set-system-proxy"].toBool()){
            QNetworkProxyFactory::setUseSystemConfiguration(true);
        }
        /*proxy set*/
        QVariantMap set_proxy = configure["set-proxy"].toMap();

        if(set_proxy["type"].toString() != ""){
            QNetworkProxy proxy;
            QString proxy_type = set_proxy["type"].toString();
            if(proxy_type == "http"){
                proxy.setType(QNetworkProxy::HttpProxy);
            }
            else if(proxy_type == "socks5"){
                proxy.setType(QNetworkProxy::Socks5Proxy);
            }
            else if(proxy_type == "ftp"){
                proxy.setType(QNetworkProxy::FtpCachingProxy);
            }
            else if(proxy_type == "httpCaching"){
                proxy.setType(QNetworkProxy::HttpCachingProxy);
            }
            else{
                qDebug()<<"Please input your type proxy (http,socks5,ftp,httpCaching)!";
                exit(0);
            }

            if(set_proxy["url"].toString() != ""){
                QString url = set_proxy["url"].toString();
                QStringList url_proxy = url.split(":");
                proxy.setHostName(url_proxy.at(0));
                proxy.setPort(url_proxy.at(1).toInt());
            }
            else{
                qDebug()<<"Please input your hostname:port Ex: 127.0.0.1:8080!";
                exit(0);
            }

            if(set_proxy["username"].toString() != ""){
                proxy.setUser(set_proxy["username"].toString());
            }

            if(set_proxy["password"].toString() != ""){
                proxy.setPassword(set_proxy["password"].toString());
            }

            QNetworkProxy::setApplicationProxy(proxy);
        }

        if(configure["set-ignsdk-proxy"].toBool()){
            QFile file("/etc/ignsdk-proxy.conf");
            QString data_ign_proxy;
            if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
                QTextStream out(&file);

                data_ign_proxy = out.readLine();

                file.close();
                if(this->debugging){
                    qDebug()<< "Enable IGNSDK global proxy setting : " << data_ign_proxy;
                }
                QStringList url_proxy = data_ign_proxy.split(":");
                QNetworkProxy proxy;
                proxy.setType(QNetworkProxy::HttpProxy);
                proxy.setHostName(url_proxy.at(0));
                proxy.setPort(url_proxy.at(1).toInt());
                if(url_proxy.at(2) != ""){
                    proxy.setUser(url_proxy.at(2));
                }
                if(url_proxy.at(3) != ""){
                    proxy.setPassword(url_proxy.at(3));
                }
                QNetworkProxy::setApplicationProxy(proxy);

            }
        }

        if(configure["websecurity"].toBool()){
            this->websecurity(true);
        }
        if(configure["name"].toString() != ""){
            this->web.setWindowTitle(configure["name"].toString());
        }

        QVariantMap window = result["window"].toMap();
        if(window["transparent"].toBool()){
            this->widgetTransparent();
        }
        if(window["noframe"].toBool()){
            this->widgetNoFrame();
        }
        if(window["notaskbar"].toBool()){
            this->widgetNoTaskbar();
        }
        if(window["fullscreen"].toBool()){
            this->getToggleFullScreen();
        }
        if(window["maximize"].toBool()){
            this->showMaximized();
        }
        if(window["width"].toInt() != 0){
            if(window["height"].toInt() != 0){
                this->widgetSize(window["width"].toInt(),window["height"].toInt());
            }
        }

        foreach (QVariant button, result["button"].toList()) {

          if (button.toString() == "back"){
              web.page()->action(QWebPage::Back)->setVisible(true);
          }
          if (button.toString() == "forward"){
              web.page()->action(QWebPage::Forward)->setVisible(true);
          }
          if (button.toString() == "stop"){
              web.page()->action(QWebPage::Stop)->setVisible(true);
          }
          if (button.toString() == "reload"){
              web.page()->action(QWebPage::Reload)->setVisible(true);
          }

        }

    }

    config_file.close();
}

void ign::saveFile(const QByteArray &data, QString filename, QString path){
    QByteArray byteArray = QByteArray::fromBase64(data);
    QString home;
    home = path+"/"+filename;
    QFile localFile(home);
    if (!localFile.open(QIODevice::WriteOnly))
        return;
    localFile.write(byteArray);
    localFile.close();
}

void ign::download(QString data,QString path){
    this->dl = new QtDownload;
    this->dl->setTarget(data);
    this->dl->save(path);
    this->dl->download();
    connect(this->dl, SIGNAL(download_signal(qint64,qint64)), this, SLOT(download_signal(qint64,qint64)));
}

void ign::download_signal(qint64 recieved, qint64 total){
    emit downloadProgress(recieved,total);
}

/*IGN SQL*/
QObject *ign::sql(){
    if(!m_sqldrv)
        m_sqldrv = new ignsql;
    return m_sqldrv;
}

/*IGN SYSTEM*/
QObject *ign::sys(){
    if(!m_ignsystem){
        m_ignsystem = new ignsystem;
    }
    return m_ignsystem;
}

/*IGN FILESYSTEM*/
QObject *ign::filesystem(){
    if(!m_filesystem){
        m_filesystem = new fs;
    }
    return m_filesystem;
}

//Check version
QString ign::sdkVersion(){
    return this->version;
}
