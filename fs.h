#ifndef FS_H
#define FS_H

#include <QObject>

class fs : public QObject
{
    Q_OBJECT
public:
    fs(QObject *parent = 0);

signals:

public slots:
    void file();
};

#endif // FS_H
