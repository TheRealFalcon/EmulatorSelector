#ifndef ROMFILTER_H
#define ROMFILTER_H


#include "romModel.h"
#include "romRegex.h"
#include <QtGui/QSortFilterProxyModel>
#include <QtCore/Qt>
#include <QObject>
//#include <QDeclarative/QDeclarativeItem>


class RomFilter : public QObject
{
    Q_OBJECT

public:
    RomFilter(QObject* parent=0);
    ~RomFilter();
    QSortFilterProxyModel* model();
    Q_INVOKABLE void setEmulator(const QString &emulatorName);
    Q_INVOKABLE void addCodeFilter(const QString &delimeter, const QString &code);
    Q_INVOKABLE void removeCodeFilter(const QString &delimiter, const QString &code);
    Q_INVOKABLE void clearCodeFilter();
    Q_INVOKABLE void setLetter(const QString &firstLetter);
    Q_INVOKABLE void startRom(const QString &executable, const QString &directory, const QString &file, const QString &arguments);
private:
    QSortFilterProxyModel* _model;
    RomRegex _regex;
    RomModel* getRoms();
};

#endif // ROMFILTER_H
