//ibnu.yahya@toroo.org
#ifndef FS_H
#define FS_H

#include <QObject>
#include <QSize>
#include <QApplication>
#include <QDir>
#include <QFile>
#include <QTextStream>
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
    bool create_file(const QString& path, const QString& data);
    QString read_file(const QString& path);
};

#endif // FS_H
