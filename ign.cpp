#include "ign.h"
#include <iostream>
using namespace std;
ign::ign(QObject *parent)
    : QObject(parent)
{
    QWebFrame *frame = web.page()->mainFrame();
    frame->addToJavaScriptWindowObject("ign",this);
}

void ign::render(QUrl w){
    this->web.load(w);
}

void ign::show(){
    this->web.show();
}

void ign::showMessage(const QString &msg)
{
    QMessageBox::information(0, "Information", msg);
}

void ign::quit(){
    this->web.close();
}
