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

class ignsystem : public QObject
{
    Q_OBJECT
public:
    explicit ignsystem(QObject *parent = 0);
    QProcess *proc;
    ignjson *jsonParse;

public slots:
    QString cliOut(const QString& cli);
    void exec(const QString& cli);
    QString hash(const QString& data, QString hash_func);
    void desktopService(const QString& link);
    void _out();
    void kill();
    bool print(const QVariant &config);

signals:
    void out(const QString& link);
};

#endif // IGNSYSTEM_H
