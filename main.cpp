/*ibnu.yahya@toroo.org*/
#include <QtGui/QApplication>
#include "ign.h"
#include <QtWebKit/QWebView>
#include <iostream>
#include <getopt.h>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    char *url = NULL;
    bool dev = false;
    int index;
    int c;

    opterr = 0;

           while ((c = getopt (argc, argv, "du:")) != -1){
             switch (c)
               {
               case 'u':
                 url = optarg;
                 break;
               case 'd':
                 dev = true;
                 break;
               case '?':
                 if (optopt == 'c')
                   fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                 else if (isprint (optopt))
                   fprintf (stderr, "Unknown option `-%c'.\n", optopt);
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

    ign w;
    QString opt = url;
    opt += "/index.html";
    if(opt.isNull()){
        w.render("http://www.igos-nusantara.or.id");
    }
    else{
        w.render(opt);
    }

    if(dev){
        w.setDev(dev);
    }
    w.show();
    return a.exec();
}
