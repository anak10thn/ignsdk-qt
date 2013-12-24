//ibnu.yahya@toroo.org
#include "fs.h"

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

bool fs::exists(const QString &path)
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

bool fs::isLink(const QString &path)
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
    QTreeView *tree = fd->findChild <QTreeView*>();
    tree->setRootIsDecorated(true);
    tree->setItemsExpandable(true);
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
