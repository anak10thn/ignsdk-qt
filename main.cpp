/*ibnu.yahya@toroo.org*/
#include <QtWidgets/QApplication>
#include "ign.h"
#include <QtWebKitWidgets/QWebView>
#include <QFileDialog>
#include <iostream>
#include <getopt.h>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ign w;
    static int verbose_flag;
    char *url = NULL;
    char *optional = NULL;
    bool dev = false;
    bool file = false;
    int index;
    int c;
    int r;
    bool version = false;
    char help[] = "Usage: ignsdk -p [PROJECT DIRECTORY]\n\nGeneral Options :\n-v\t--version\t\toutput version information and exit\n-d\t--dev\t\t\tWeb Inspector Enable\n-r\t--dev-remote [port]\tRemote debugging\n\nWindow options :\n--transparent\tTransparent Mode\n--noFrame\tFrame Disable\n";
    opterr = 0;
    static struct option long_options[] =
                 {
                   {"verbose", no_argument,       &verbose_flag, 1},
                   {"brief",   no_argument,       &verbose_flag, 0},
                   {"dev",     no_argument,       0, 'd'},
                   {"file",     required_argument,       0, 'f'},
                   {"transparent",  no_argument,       0, 't'},
                   {"noFrame",  no_argument,       0, 'n'},
                   {"help",  no_argument,       0, 'h'},
                   {"project",      required_argument, 0, 'p'},
                   {"dev-remote",      required_argument, 0, 'r'},
                   {"version",  no_argument,       0, 'v'},
                   {0, 0, 0, 0}
                 };

               int option_index = 0;

           while ((c = getopt_long (argc, argv, "vdnhf:tp:r:",long_options,&option_index)) != -1){
             switch (c)
               {
               case 'p':
                 url = optarg;
                 break;
               case 'd':
                 dev = true;
                  w.setDev(dev);
                 break;
               case 'f':
                file = true;
                optional = optarg;
               break;
               case 'r':
                r = atoi(optarg);
                w.setDevRemote(r);
               break;
               case 'n':
                 w.widgetNoFrame();
               break;
               case 't':
                 w.widgetTransparent();
               break;
               case 'v':
                 version = true;
               break;
               case 'h':
                 printf("%s\n",help);
                 exit(0);
               break;
               case '?':
                 if (optopt == 'c')
                   fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                 else if (isprint (optopt))
                   fprintf (stderr, "Unknown option `-%c'.\n\nUsage: ignsdk -p [PROJECT DIRECTORY]\n\nGeneral Options :\n-v\t--version\t\toutput version information and exit\n-d\t--dev\t\t\tWeb Inspector Enable\n-r\t--dev-remote [port]\tRemote debugging\n\nWindow options :\n--transparent\tTransparent Mode\n--noFrame\tFrame Disable\n", optopt);
                 else
                   fprintf (stderr,
                            "Unknown option character `\\x%x'.\n",
                            optopt);
                 return 1;
               default:
                 abort ();
               }
           }

    for (index = optind; index < argc; index++){
       printf ("Non-option argument %s\n", argv[index]);
    }

    if(version){
        qDebug() << "IGNSDK Version : "<< w.sdkVersion();
        exit(0);
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

        w.render(opt);
        w.config(url);
        w.show();

    }
    else{
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
            w.config(directory);
            w.render(directory+"/index.html");
            w.show();
        }
        else {
            w.render("http://www.igos-nusantara.or.id");
            w.show();
        }
    }

    return a.exec();
}
