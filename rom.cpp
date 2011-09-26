#include "rom.h"
#include <QtCore/QDebug>
#include <QtGui/QStandardItemModel>
#include <QtCore/QStringList>

Rom::Rom(QObject *parent)
    : QSortFilterProxyModel(parent)
{
    qDebug() << "hello there" << endl;

    QStandardItemModel *fileModel = new QStandardItemModel();
//    foreach (Emulator emulator, emulatorModel->emulatorList()) {
//        foreach (QString searchPath, emulator.searchPaths) {
//            QDir dir(searchPath);
//            QStringList searchFiles = dir.entryList(QStringList() << "*" + emulator.extension, QDir::Files);
//            foreach (QString searchFile, searchFiles) {
//                QStandardItem *fileItem = new QStandardItem(searchFile);
//                QStandardItem *directoryItem = new QStandardItem(searchPath);
//                QStandardItem *extensionItem = new QStandardItem(emulator.extension);
//                QStandardItem *exeItem = new QStandardItem(emulator.path);
//                QStandardItem *argsItem = new QStandardItem(emulator.args);
//                QList<QStandardItem*> row;
//                row << fileItem << directoryItem << extensionItem << exeItem << argsItem;
//                fileModel->appendRow(row);
//            }
//        }
//    }

    //proxyModel = new QSortFilterProxyModel();
    //proxyModel->setSourceModel(fileModel);
    this->setSourceModel(fileModel);
}
