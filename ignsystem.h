#ifndef IGNSYSTEM_H
#define IGNSYSTEM_H

#include <QObject>
#include <QtGlobal>

class ignsystem : public QObject
{
    Q_OBJECT
public:
    ignsystem(QObject *parent = 0);
public slots:
    void tes();
};

#endif // IGNSYSTEM_H
