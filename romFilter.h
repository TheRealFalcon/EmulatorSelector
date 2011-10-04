#ifndef ROMFILTER_H
#define ROMFILTER_H

#include <QtGui/QSortFilterProxyModel>
#include "romModel.h"
#include <QtCore/Qt>
//#include <QtCore/QObject>
#include <QObject>
#include <QDeclarativeItem>

class RomFilter : public QObject
{
    Q_OBJECT

public:
    RomFilter(QObject* parent=0);
    ~RomFilter();
    QSortFilterProxyModel* model();
    Q_INVOKABLE void onEmulatorSelectionChanged(QString emulatorName);
private:
    QSortFilterProxyModel* _model;
    QString _extensions;
    QString regex(QString firstLetter, QString code, QString extension);
    RomModel* getRoms();
};

#endif // ROMFILTER_H
