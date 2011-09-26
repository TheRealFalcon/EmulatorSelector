#ifndef ROMMODEL_H
#define ROMMODEL_H

#include "rom.h"
#include <QtCore/QAbstractListModel>
#include <QtCore/Qt>
#include <QtCore/QVariant>

class RomModel : public QAbstractListModel
{
public:
    enum RomRoles {
        FileRole = Qt::UserRole + 1,
        DirectoryRole,
        ExtensionRole,
        ExecutableRole,
        ArgumentsRole
    };
    RomModel(QObject *parent = 0);
    void addRom(Rom rom);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
private:
    QList<Rom> romList;
};

#endif // ROM_H
