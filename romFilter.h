#ifndef ROMFILTER_H
#define ROMFILTER_H

#include <QtGui/QSortFilterProxyModel>
#include "romModel.h"
#include <QtCore/Qt>
//#include <QtCore/QObject>
#include <QObject>

class RomFilter : public QObject
{
    Q_OBJECT

public:
    RomFilter(QObject* parent=0);
    ~RomFilter();
    QSortFilterProxyModel* model();
    Q_INVOKABLE void onEmulatorSelectionChanged();
private:
    QSortFilterProxyModel* _model;
    RomModel* getRoms();
};

#endif // ROMFILTER_H
