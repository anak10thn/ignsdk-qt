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
#include <QDirIterator>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>
#include <QDateTime>
#include "ignjson.h"

/** @name fs.h
*/
///@{
class fs : public QObject
{
    Q_OBJECT

public:
    fs(QObject *parent = 0);
    ignjson *json;

signals:

public slots:
	/// @details Removes the file specified by path
	/// @param path : path to file to be removed
	/// @return Returns true if successful; otherwise returns false.
    bool fileRemove(const QString& path);
	/// @details Get Application path
	/// @return Returns the directory that contains ignSDK executable.
    QString appPath();
	/// @details Removes the file specified by path
	/// @return Returns the absolute path of the user's home directory.
    QString homePath();
	/// @details Write data to file specified by path
	/// @param path : path to file
    /// @param data : data to be wrote
	/// @return Returns true if successful; otherwise returns false.
    bool fileWrite(const QString& path, const QString& data);
	/// @details Read data from file specified by path
	/// @param path : path to file to read
	/// @return Returns data as string, return empty string if failing
    QString fileRead(const QString& path);
	/// @details Create or remove directory
	/// @param opt : "create" "remove" 
    /// @param path : directory path
	/// @return Returns data as string, return empty string if failing
    bool dir(const QString& opt,const QString& path);
    //checking file or directory
	/// @param path : path to file
	/// @return Returns true if the file specified by path exists; otherwise returns false.
    bool isExist(const QString &path);
	/// @param path : path to file
	/// @return Returns true if path points to a directory or to a symbolic link to a directory; otherwise returns false.
    bool isDirectory(const QString &path);
	/// @param path : path to file
	/// @return Returns true if path points to a file or to a symbolic link to a file. Returns false if the object points to something which isn't a file, such as a directory.
    bool isFile(const QString &path);
	/// @param path : path to file
	/// @return Returns true if the file path name is absolute, otherwise returns false if the path is relative.
    bool isAbsolute(const QString &path);
	/// @param path : path to file
	/// @return Returns true if the file is executable; otherwise returns false.
    bool isExecutable(const QString &path);
	/// @param path : path to file
	/// @return Returns true if the user can read the file; otherwise returns false.
    bool isReadable(const QString &path);
	/// @param path : path to file
	/// @return Returns true if the user can write to the file; otherwise returns false.
    bool isWritable(const QString &path);
	/// @param path : path to file
	/// @return Returns true if this object points to a symbolic link (or to a shortcut on Windows); otherwise returns false.
    bool isSymlink(const QString &path);
	
	/// @details Copies the file currently specified by src to a file called des. 
	/// @param src : source file
    /// @param des : destination file
	/// @return Returns true if successful; otherwise returns false.
    bool copy(const QString &src, const QString &des);
	
	/// @details Select a file with open file dialog.
	/// @return Returns path to selected file.
    QString openFileDialog();
	/// @details Select a directory with open directory dialog.
	/// @return Returns path to selected file.
    QString openDirDialog();
	/// @details Open save dialog file, the file doesn't have to be existed.
	/// @return Returns path to selected or new file.
    QString saveFileDialog();
	/// @details Select a file with open file dialog.
	/// @return Returns path to selected file.
    QString saveFileDialog(const QVariant &config);
	
	/// @param path : path to directory
	/// @return Returns list of available item inside directory
    QStringList list(const QString &path);	
	/// @param path : path to file
	/// @return Returns complete information from file specified by path
    QVariant info(const QString &path);
};
///@}
#endif // FS_H
