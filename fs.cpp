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
