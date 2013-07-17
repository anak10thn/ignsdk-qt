//ibnu.yahya@toroo.org
#ifndef FS_H
#define FS_H

#include <QObject>
#include <QSize>
#include <QApplication>
#include <QDir>
class fs : public QObject
{
    Q_OBJECT
public:
    fs(QObject *parent = 0);

signals:

public slots:
    void file();
    QString app_dir_path();
    QString home_path();
};

#endif // FS_H
