#ifndef IGNSYSTEM_H
#define IGNSYSTEM_H

#include <QObject>
#include <QtGlobal>
#include <QProcess>
class ignsystem : public QObject
{
    Q_OBJECT
public:
    ignsystem(QObject *parent = 0);
public slots:
    QString cliOut(const QString& cli);
    void exec(const QString& cli);
};

#endif // IGNSYSTEM_H
