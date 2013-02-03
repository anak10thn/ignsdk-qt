#include "ign.h"
#include <iostream>
using namespace std;
ign::ign(QObject *parent)
    : QObject(parent)
{

}

void ign::showMessage(const QString &msg)
{
    QMessageBox::information(0, "Information", msg);
}

QString ign::quit(){
    emit quitRequested();

    return "yes";
}
