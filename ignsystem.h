#ifndef IGNSYSTEM_H
#define IGNSYSTEM_H

#include <QObject>
#include <QtGlobal>
#include <QProcess>
#include <QCryptographicHash>
#include <QDesktopServices>
#include <QUrl>
class ignsystem : public QObject
{
    Q_OBJECT
public:
    ignsystem(QObject *parent = 0);
public slots:
    QString cliOut(const QString& cli);
    void exec(const QString& cli);
    QString hash(const QString& data, QString hash_func);
    void desktopService(const QString& link);
};

#endif // IGNSYSTEM_H
