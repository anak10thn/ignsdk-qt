//ibnu.yahya@toroo.org

#include "ign.h"
#include "fs.h"
#include "cmath"
#include <QtCore/QVariant>
#include <qjson/parser.h>
#include <qjson/parserrunnable.h>
#include <qjson/serializer.h>
#include <qjson/serializerrunnable.h>
#include <qjson/qjson_export.h>
#include <qjson/qobjecthelper.h>
#include <iostream>
using namespace std;
ign::ign(QObject *parent)
    : QObject(parent),
    m_ignsystem(0),
    m_sqldrv(0)
{
    this->version = "1.0.9";
    frame = web.page()->mainFrame();
    connect(frame,SIGNAL(javaScriptWindowObjectCleared()), SLOT(ignJS()));
    this->filesystem = new fs;
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

void ign::render(QString w){
     this->web.load(QUrl(w));

    /*QFile jqueryfile;

    QString jquery;
    jqueryfile.setFileName(":/js/jquery.js");
    if(jqueryfile.open(QIODevice::ReadOnly)){
        jquery = jqueryfile.readAll();
        frame->evaluateJavaScript(jquery);
    }
    jqueryfile.close();

    QFile incJsFile;
    QString incJs;
    incJsFile.setFileName(":/js/include.js");
    if(incJsFile.open(QIODevice::ReadOnly)){
        incJs = incJsFile.readAll();
        frame->evaluateJavaScript(incJs);
    }
    incJsFile.close();

    frame->evaluateJavaScript("include('tes')");*/
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

void ign::back(){
    this->web.page()->action(QWebPage::Back)->setVisible(true);
}

void ign::forward(){
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

void ign::websecurity(bool c){
    web.settings()->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls,c);
}

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

void ign::widgetTransparent(){
    QPalette pal = this->web.palette();
    pal.setBrush(QPalette::Base, Qt::transparent);
    this->web.setPalette(pal);
    this->web.setAttribute(Qt::WA_OpaquePaintEvent, false);
    this->web.setAttribute(Qt::WA_TranslucentBackground, true);
}

QString ign::cliOut(const QString& cli){
    QProcess os;
    os.start(cli);
    int pid = os.pid();
    qDebug() << pid;
    os.waitForFinished(-1);
    return os.readAllStandardOutput();

}

void ign::exec(const QString &cli){
    QProcess os;
    os.startDetached("/bin/sh -c \""+cli+"\"");
}

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

void ign::mousePressEvent(QMouseEvent *event)
{
    qDebug()<<event->type();
}

void ign::config(QString path){
    QFile config_file;
    QDir::setCurrent(path);
    config_file.setFileName("ignsdk.json");
    QByteArray config;
    if(config_file.open(QIODevice::ReadOnly)){
        config = config_file.readAll();
        QJson::Parser parse;
        bool ok;

        QVariantMap result = parse.parse(config, &ok).toMap();
        if (!ok) {
          qFatal("An error occurred during parsing");
          exit (1);
        }

        QVariantMap configure = result["config"].toMap();

        if(configure["debug"].toBool()){
            this->setDev(true);
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
              this->back();
          }
          if (button.toString() == "forward"){
              this->forward();
          }
          if (button.toString() == "stop"){
              this->stop();
          }
          if (button.toString() == "reload"){
              this->reload();
          }

        }

    }

    config_file.close();
}

QString ign::hash(const QString &data,QString hash_func){
    QByteArray hash;
    QByteArray byteArray = data.toLatin1();
    if(hash_func == "md4"){
        hash=QCryptographicHash::hash(byteArray,QCryptographicHash::Md4);
    }
    else if(hash_func == "md5"){
        hash=QCryptographicHash::hash(byteArray,QCryptographicHash::Md5);
    }
    else if(hash_func == "sha1"){
        hash=QCryptographicHash::hash(byteArray,QCryptographicHash::Sha1);
    }

    return hash.toHex();
}

QString ign::homePath(){
    return this->filesystem->home_path();
}

bool ign::createFile(const QString &path, const QString &data){
    return this->filesystem->create_file(path,data);
}

QString ign::readFile(const QString &path){
    return this->filesystem->read_file(path);
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
bool ign::mkdir(const QString &path){
    return this->filesystem->dir(path,"create");
}

bool ign::dirExist(const QString &path){
    return this->filesystem->dir(path,"check");
}

bool ign::rmdir(const QString &path){
    return this->filesystem->dir(path,"remove");
}

bool ign::fileExist(const QString &path){
    return this->filesystem->file(path,"check");
}

bool ign::fileRemove(const QString &path){
    return this->filesystem->file(path,"remove");
}

//Check version
QString ign::sdkVersion(){
    return this->version;
}

/*void ign::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        QMessageBox::information(0, "Information", "press");
        mMoving = true;
        mLastMousePosition = event->pos();
    }
}

void ign::mouseMoveEvent(QMouseEvent *event)
{
    if( event->buttons().testFlag(Qt::LeftButton) && mMoving)
    {
        this->web.move(this->web.pos() + (event->pos() - mLastMousePosition));
        mLastMousePosition = event->pos();
    }
}

void ign::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        mMoving = false;
    }
}*/
