//ibnu.yahya@toroo.org
#include "fs.h"
#include <QDebug>

fs::fs(QObject *parent) :
    QObject(parent)
{

}

bool fs::fileRemove(const QString &path){
    QFile file(path);
    return file.remove();
}

bool fs::fileWrite(const QString &path, const QString &data){
    QFile file(path);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&file);
        out << data;
        return true;
    }
    else {
        return false;
    }
    file.close();
}

QString fs::fileRead(const QString &path){
    //QStringList fields;
    QFile file(path);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream out(&file);

        /*while(!out.atEnd()){
            fields.append(out.readLine());

        }*/
        QString data = out.readLine();
        /*foreach (const QString text, fields){
            qDebug() << text.toStdString();
        }*/
        file.close();

        return data;
    }
}

QString fs::appPath(){
    return QApplication::applicationDirPath();
}

QString fs::homePath(){
    QString home = QDir::homePath();
    return home;
}

bool fs::dir(const QString &opt, const QString &path){
    QDir dir;
    if(opt == "create"){
        return dir.mkdir(path);
    }
    else if(opt == "remove"){
        return dir.rmdir(path);
    }
}

bool fs::isExist(const QString &path)
{
    return QFile::exists(path);
}

bool fs::isDirectory(const QString &path)
{
    return QFileInfo(path).isDir();
}

bool fs::isFile(const QString &path)
{
    return QFileInfo(path).isFile();
}

bool fs::isAbsolute(const QString &path)
{
   return QFileInfo(path).isAbsolute();
}

bool fs::isExecutable(const QString &path)
{
   return QFileInfo(path).isExecutable();
}

bool fs::isSymlink(const QString &path)
{
   return QFileInfo(path).isSymLink();
}

bool fs::isReadable(const QString &path)
{
   return QFileInfo(path).isReadable();
}

bool fs::isWritable(const QString &path)
{
   return QFileInfo(path).isWritable();
}

bool fs::copy(const QString &src, const QString &des){
    if(QFile::exists(des)){
        QFile::remove(des);
    }
    return QFile::copy(src,des);
}

QString fs::openFileDialog(){
    QFileDialog *fd = new QFileDialog;
    int result = fd->exec();
    if (result)
    {
        QString directory = fd->selectedFiles()[0];
        return directory;
    }
    else {
        return false;
    }
}

QString fs::openDirDialog(){
    QFileDialog *fd = new QFileDialog;
#ifdef Linux
    QTreeView *tree = fd->findChild <QTreeView*>();
    tree->setRootIsDecorated(true);
    tree->setItemsExpandable(true);
#endif
    fd->setFileMode(QFileDialog::Directory);
    fd->setOption(QFileDialog::ShowDirsOnly);
    fd->setViewMode(QFileDialog::Detail);
    int result = fd->exec();
    QString directory;
    if (result)
    {
        directory = fd->selectedFiles()[0];
        return directory;
    }
}

QStringList fs::list(const QString &path){
    QDirIterator dirIt(path,QDirIterator::Subdirectories);
    QStringList list;
    while (dirIt.hasNext()) {
        dirIt.next();
        list.push_front(dirIt.filePath());
    }
    return list;
}

QVariant fs::info(const QString &path){
    QVariantMap map;
    QFileInfo info(path);
    QVariant size = info.size();
    QVariant absoluteFilePath = info.absoluteFilePath();
    QVariant baseName = info.baseName();
    QVariant isSymlink = info.isSymLink();
    QVariant isAbsolute = info.isAbsolute();
    QVariant isBundle = info.isBundle();
    QVariant isDir = info.isDir();
    QVariant isExecutable = info.isExecutable();
    QVariant isFile = info.isFile();
    QVariant isHidden = info.isHidden();
    QVariant isReadable = info.isReadable();
    QVariant isRelative = info.isRelative();
    QVariant isRoot = info.isRoot();
    QVariant isWritable = info.isWritable();
    QVariant bundleName = info.bundleName();
    QVariant exists = info.exists();
    QVariant fileName = info.fileName();
    QVariant filePath = info.filePath();
    QVariant group = info.group();
    QVariant lastModified = info.lastModified();
    QVariant lastRead = info.lastRead();
    map.insert("size",size);
    map.insert("absoluteFilePath",absoluteFilePath);
    map.insert("baseName",baseName);
    map.insert("isSymlink",isSymlink);
    map.insert("isAbsolute",isAbsolute);
    map.insert("isBundle",isBundle);
    map.insert("isDir",isDir);
    map.insert("isExecutable",isExecutable);
    map.insert("isFile",isFile);
    map.insert("isHidden",isHidden);
    map.insert("isReadable",isReadable);
    map.insert("isRelative",isRelative);
    map.insert("isRoot",isRoot);
    map.insert("isWritable",isWritable);
    map.insert("filePath",filePath);
    map.insert("bundleName",bundleName);
    map.insert("exists",exists);
    map.insert("fileName",fileName);
    map.insert("group",group);
    map.insert("lastModified",lastModified);
    map.insert("lastRead",lastRead);
    QJsonDocument json_enc = QJsonDocument::fromVariant(map);
    return json_enc.toVariant();
}
