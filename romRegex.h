#ifndef ROMREGEX_H
#define ROMREGEX_H

#include <QObject>
#include <QtCore/QMultiHash>

class RomRegex
{
public:
    RomRegex();
    void setFirstLetter(const QString &firstLetter);
    void setCode(const QString &delimiter, const QString &code);
    void removeCode(const QString &delimiter, const QString &code);
    void removeCodes();
    void setExtension(const QString &extension);
    QString pattern();
private:
    QString _firstLetter;
    QMultiHash<QString, QString> _codes;
    QString _extension;
};

#endif // ROMREGEX_H
