#include "ignsystem.h"
#include <QDebug>

ignsystem::ignsystem(QObject *parent)
    : QObject(parent),
      jsonParse(0),
      proc(0)
{

}

QString ignsystem::cliOut(const QString& cli){
    QProcess os;
    os.setProcessChannelMode(QProcess::MergedChannels);
    os.start(cli);
    int pid = os.pid();
    qDebug() << "Executing process with PID" << pid;
    os.waitForFinished(-1);
    return os.readAllStandardOutput();
}

QString ignsystem::hash(const QString &data,QString hash_func){
    QByteArray hash;
    QByteArray byteArray = data.toLatin1();
    if(hash_func == "md4"){
        hash=QCryptographicHash::hash(byteArray,QCryptographicHash::Md4);
    }
    else if(hash_func == "md5"){
        hash=QCryptographicHash::hash(byteArray,QCryptographicHash::Md5);
    }
    else if(hash_func == "sha1"){
        hash=QCryptographicHash::hash(byteArray,QCryptographicHash::Sha1);
    }
    else if(hash_func == "sha224"){
        hash=QCryptographicHash::hash(byteArray,QCryptographicHash::Sha224);
    }
    else if(hash_func == "sha256"){
        hash=QCryptographicHash::hash(byteArray,QCryptographicHash::Sha256);
    }
    else if(hash_func == "sha384"){
        hash=QCryptographicHash::hash(byteArray,QCryptographicHash::Sha384);
    }
    else if(hash_func == "sha512"){
        hash=QCryptographicHash::hash(byteArray,QCryptographicHash::Sha512);
    }

    return hash.toHex();
}

void ignsystem::desktopService(const QString &link){
    QDesktopServices ::openUrl(QUrl(link));
}

QObject *ignsystem::exec(const QString& cli){
    proc = new ignprocess;
    proc->exec(cli);
    return proc;
}

bool ignsystem::print(const QVariant &config){
    QVariantMap conf = jsonParse->jsonParser(config).toVariantMap();
    QPrinter print;
    QTextDocument *doc = new QTextDocument();

    QString type = conf["type"].toString();
    QString txt = conf["content"].toString();
    QString out = conf["out"].toString();

    if(type == "html")
    {
        doc->setHtml(txt);
    }
    else
    {
        doc->setPlainText(txt);
    }

    if(out == "pdf"){
        print.setOutputFormat(QPrinter::PdfFormat);
    }

    QPrintDialog *dialog = new QPrintDialog(&print);
    if (dialog->exec() != QDialog::Accepted)
    {
        return false;
    }
    else
    {
        doc->print(&print);
        delete doc;
        return true;
    }
}
