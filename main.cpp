//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.
//      by ibnu.yahya@toroo.org
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
           printf("%s",url);
    for (index = optind; index < argc; index++){
       printf ("Non-option argument %s\n", argv[index]);
    }

    ign w;
    QString opt = url;
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
