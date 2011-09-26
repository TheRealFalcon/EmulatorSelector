#include "romModel.h"
#include "rom.h"
#include <QtCore/QDebug>
#include <QtGui/QStandardItemModel>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

RomModel::RomModel(QObject *parent)
    : QAbstractListModel(parent)
{
    QHash<int, QByteArray> roles;
    roles[FileRole] = "file";
    roles[DirectoryRole] = "directory";
    roles[ExtensionRole] = "extension";
    roles[ExecutableRole] = "executable";
    roles[ArgumentsRole] = "arguments";
    setRoleNames(roles);

//    QStandardItemModel *fileModel = new QStandardItemModel();
//    fileModel->appendRow(new QStandardItem("Hello"));
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
    //this->setSourceModel(fileModel);

    Rom rom;
    rom.file = "ccc";
    rom.extension = "def";
    this->addRom(rom);
}

void RomModel::addRom(Rom rom)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    romList << rom;
    endInsertRows();
}

int RomModel::rowCount(const QModelIndex & parent) const {
     return romList.count();
 }


QVariant RomModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() > romList.count()) {
        return QVariant();
    }

    const Rom &rom = romList[index.row()];

    switch (role) {
    case FileRole:
        return rom.file;
    case DirectoryRole:
        return rom.directory;
    case ExtensionRole:
        return rom.extension;
    case ExecutableRole:
        return rom.executable;
    case ArgumentsRole:
        return rom.arguments;
    }
    return QVariant();
}

