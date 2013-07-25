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
    char *optional = NULL;
    bool dev = false;
    bool file = false;
    int index;
    int c;
    char version[] = "version 1.0.1 status experiment";
    char help[] = "Usage: ignsdk -p [PROJECT DIRECTORY]\n\nGeneral Options :\n--version\toutput version information and exit\n--dev\t\tWeb Inspector Enable\n\nWindow options :\n--transparent\tTransparent Mode\n--noFrame\tFrame Disable\n";
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
                   {"version",  no_argument,       0, 'v'},
                   {0, 0, 0, 0}
                 };

               int option_index = 0;

           while ((c = getopt_long (argc, argv, "vdnhf:tp:",long_options,&option_index)) != -1){
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
               case 'n':
                 w.widgetNoFrame();
               break;
               case 't':
                 w.widgetTransparent();
               break;
               case 'v':
                 printf("ignsdk %s\n",version);
                 exit(0);
               break;
               case 'h':
                 printf("%s\n",help);
                 exit(0);
               break;
               case '?':
                 if (optopt == 'c')
                   fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                 else if (isprint (optopt))
                   fprintf (stderr, "Unknown option `-%c'.\n\nUsage: ignsdk -p [PROJECT DIRECTORY]\n\nGeneral Options :\n--version\toutput version information and exit\n--dev\t\tWeb Inspector Enable\n\nWindow options :\n--transparent\tTransparent Mode\n--noFrame\tFrame Disable\n", optopt);
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

    if(opt.isEmpty()){
        w.render("http://www.igos-nusantara.or.id");
    }
    else{
        w.pathApp = opt;
        if(file){
            opt += "/";
            opt += optional;
        }
        else {
            opt += "/index.html";
        }
        w.render(opt);
        w.config(url);

    }
    w.show();
    return a.exec();
}
