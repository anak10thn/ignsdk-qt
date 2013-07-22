//ibnu.yahya@toroo.org
#include "fs.h"

fs::fs(QObject *parent) :
    QObject(parent)
{

}

void fs::file(){

}

QString fs::app_dir_path(){
    return QApplication::applicationDirPath();
}

QString fs::home_path(){
    QString home = QDir::homePath();
    return home;
}

bool fs::create_file(const QString &path, const QString &data){
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

QString fs::read_file(const QString &path){
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
