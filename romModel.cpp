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

