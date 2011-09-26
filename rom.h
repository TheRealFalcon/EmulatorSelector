#ifndef ROM_H
#define ROM_H

#include <QtGui/QSortFilterProxyModel>

class Rom : public QSortFilterProxyModel
{
public:
    Rom(QObject *parent = 0);
};

#endif // ROM_H
