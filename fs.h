//ibnu.yahya@toroo.org
#ifndef FS_H
#define FS_H

#include <QObject>
#include <QSize>
#include <QtWidgets/QApplication>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QTreeView>
class fs : public QObject
{
    Q_OBJECT
public:
    fs(QObject *parent = 0);

signals:

public slots:
    bool fileRemove(const QString& path);
    QString appPath();
    QString homePath();
    bool fileWrite(const QString& path, const QString& data);
    QString fileRead(const QString& path);
    bool dir(const QString& opt,const QString& path);
    //checking file or directory
    bool exists(const QString &path);
    bool isDirectory(const QString &path);
    bool isFile(const QString &path);
    bool isAbsolute(const QString &path);
    bool isExecutable(const QString &path);
    bool isReadable(const QString &path);
    bool isWritable(const QString &path);
    bool isLink(const QString &path);
    bool copy(const QString &src, const QString &des);
    QString openFileDialog();
    QString openDirDialog();
};

#endif // FS_H
