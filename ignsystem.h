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
    explicit ignsystem(QObject *parent = 0);
    QProcess *proc;

public slots:
    QString cliOut(const QString& cli);
    void exec(const QString& cli);
    QString hash(const QString& data, QString hash_func);
    void desktopService(const QString& link);
    void _out();
    void kill();

signals:
    void out(const QString& link);
};

#endif // IGNSYSTEM_H
