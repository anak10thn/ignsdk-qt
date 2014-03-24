#ifndef IGNNETWORK_H
#define IGNNETWORK_H

#include <QObject>

class ignnetwork : public QObject
{
    Q_OBJECT
public:
    explicit ignnetwork(QObject *parent = 0);
public slots:
    QString myIp();
};

#endif // IGNNETWORK_H
