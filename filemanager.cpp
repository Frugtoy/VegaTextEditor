#include "filemanager.h"

FileManager::FileManager()
{

}

FileManager::~FileManager()
{

}

void FileManager::createFile( QString &filepath)
{
    QFile file(filepath);
    file.open(QIODevice::WriteOnly);
    file.close();
}
void FileManager::saveFile(QString&filepath,QString& text)
{
    QFile file (filepath);
    QTextStream fstream(&file);
    file.open(QIODevice::WriteOnly);
    fstream<<text;
    file.flush();
    file.close();
}
QString FileManager::openFile(QString filepath)
{
    QFile file(filepath);
    QTextStream fstream(&file);
    file.open(QIODevice::ReadOnly);
    QString text = fstream.readAll();
    file.close();
    return text;
}

