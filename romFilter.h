#ifndef ROMFILTER_H
#define ROMFILTER_H


#include "romModel.h"
#include "romRegex.h"
#include <QtGui/QSortFilterProxyModel>
#include <QtCore/Qt>
#include <QObject>
#include <QDeclarativeItem>


class RomFilter : public QObject
{
    Q_OBJECT

public:
    RomFilter(QObject* parent=0);
    ~RomFilter();
    QSortFilterProxyModel* model();
    Q_INVOKABLE void setEmulator(QString emulatorName);
    Q_INVOKABLE void addCodeFilter(QString delimeter, QString code);
    Q_INVOKABLE void removeCodeFilter(QString delimiter, QString code);
    Q_INVOKABLE void setLetter(QString firstLetter);
    Q_INVOKABLE void startRom();
private:
    QSortFilterProxyModel* _model;
    RomRegex _regex;
    RomModel* getRoms();
};

#endif // ROMFILTER_H
