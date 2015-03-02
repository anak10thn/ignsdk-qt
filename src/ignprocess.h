#ifndef IGNPROCESS_H
#define IGNPROCESS_H

#include <QObject>
#include <QProcess>

class ignprocess : public QObject
{
    Q_OBJECT
public:
    explicit ignprocess(QObject *parent = 0);
    QProcess proc;

signals:
    void out(const QString& link);

public slots:
    void exec(const QString& cli);
    void _out();
    void kill();
};

#endif // IGNPROCESS_H
