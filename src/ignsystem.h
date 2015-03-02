#ifndef IGNSYSTEM_H
#define IGNSYSTEM_H

#include <QObject>
#include <QtGlobal>
#include <QProcess>
#include <QCryptographicHash>
#include <QDesktopServices>
#include <QUrl>
#include <QDebug>
#include <QTextDocument>
#include <QPrinter>
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#include "ignjson.h"
#include "ignprocess.h"

class ignsystem : public QObject
{
    Q_OBJECT
public:
    explicit ignsystem(QObject *parent = 0);
    ignjson *jsonParse;
    ignprocess *proc;

public slots:
    QString cliOut(const QString& cli);
    QObject *exec(const QString& cli);
    QString hash(const QString& data, QString hash_func);
    void desktopService(const QString& link);
    bool print(const QVariant &config);

signals:

};

#endif // IGNSYSTEM_H
