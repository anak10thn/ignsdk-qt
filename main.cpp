/*ibnu.yahya@toroo.org*/
#include <QtWidgets/QApplication>
#include "ign.h"
#include <QtWebKitWidgets/QWebView>
#include <QFileDialog>
#include <iostream>
#include <getopt.h>
#include "version.h"
#include <QCommandLineParser>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ign w;

    QString url = NULL;
    bool file = false;
    QString optional;

    QCommandLineParser cmd_parser;
    cmd_parser.setApplicationDescription("IGOS Nusantara Software Development Kit");

    QCommandLineOption cmd_project(QStringList() << "p" << "project", "Specify project directory", "directory");
    cmd_parser.addOption(cmd_project);
    QCommandLineOption cmd_file(QStringList() << "f" << "file", "Load specific HTML file", "file");
    cmd_parser.addOption(cmd_file);
    QCommandLineOption cmd_dev(QStringList() << "d" << "development", "Activate development mode");
    cmd_parser.addOption(cmd_dev);
    QCommandLineOption cmd_remote(QStringList() << "r" << "remote", "Activate remote debugging", "port");
    cmd_parser.addOption(cmd_remote);
    QCommandLineOption cmd_version(QStringList() << "v" << "version", "Show version");
    cmd_parser.addOption(cmd_version);
    cmd_parser.addHelpOption();

    cmd_parser.process(a);

    if (cmd_parser.isSet(cmd_version)) {
      printf("IGNSDK version %s (%s). Compiled on %s %s. Maintained by %s.\n", IGNSDK_VERSION, IGNSDK_CODENAME, __DATE__, __TIME__, IGNSDK_MAINTAINER);
      exit(0);
    }

    url = cmd_parser.value(cmd_project);

    if (cmd_parser.isSet(cmd_remote)) {
      w.setDevRemote(cmd_parser.value(cmd_remote).toInt());
    }

    if (cmd_parser.isSet(cmd_file)) {
      file = true;
      optional = cmd_parser.value(cmd_file);
    }

    QString opt = url;
    QString path = url;
    if(!opt.isEmpty()){
        w.pathApp = opt;
        /*icon set*/
        a.setWindowIcon(QIcon(path+"icons/app.png"));

        if(file){
            opt += "/";
            opt += optional;
        }
        else {
            opt += "/index.html";
        }

        if (QFile::exists(opt)){
          w.render(opt);
          w.config(url);
          w.show();
        } else {
          qDebug() << "Error:" << opt << "is not exist.";
          exit(1);
        }

    }
    else{
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
            if (QFile::exists(directory + "/index.html"))
            {
              w.config(directory);
              w.render(directory+"/index.html");
              w.show();
            } else {
              qDebug() << "Error:" << (directory + "/index.html") << "is not exist.";
              exit(1);
            }
        }
        else {
            exit(1);
        }
    }

    return a.exec();
}
