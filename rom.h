#ifndef ROM_H
#define ROM_H

#include <QtGui/QSortFilterProxyModel>
#include <QtCore/Qt>

class Rom : public QSortFilterProxyModel
{
public:
    enum RomRoles {
        FileRole = Qt::UserRole + 1,
        DirectoryRole,
        ExtensionRole,
        ExecutableRole,
        ArgumentsRole
    };
    Rom(QObject *parent = 0);
};

#endif // ROM_H
