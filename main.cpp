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
    ign w;
    static int verbose_flag;
    char *url = NULL;
    bool dev = false;
    int index;
    int c;

    opterr = 0;
    static struct option long_options[] =
                 {
                   {"verbose", no_argument,       &verbose_flag, 1},
                   {"brief",   no_argument,       &verbose_flag, 0},
                   {"dev",     no_argument,       0, 'd'},
                   {"transparent",  no_argument,       0, 't'},
                   {"noFrame",  no_argument,       0, 'f'},
                   {"url",      required_argument, 0, 'u'},
                   {0, 0, 0, 0}
                 };

               int option_index = 0;

           while ((c = getopt_long (argc, argv, "dftu:",long_options,&option_index)) != -1){
             switch (c)
               {
               case 'u':
                 url = optarg;
                 break;
               case 'd':
                 dev = true;
                  w.setDev(dev);
                 break;
               case 'f':
                 w.WidgetNoFrame();
               break;
               case 't':
                 w.WidgetTransparent();
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

    QString opt = url;
    opt += "/index.html";
    if(opt.isNull()){
        w.render("http://www.igos-nusantara.or.id");
    }
    else{
        w.render(opt);
    }
    w.show();
    return a.exec();
}
