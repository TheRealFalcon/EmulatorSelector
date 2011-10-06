#ifndef ROMREGEX_H
#define ROMREGEX_H

#include <QObject>

class RomRegex
{
public:
    RomRegex();
    void setFirstLetter(const QString &firstLetter);
    void setCode(const QString &delimiter, const QString &code);
    void setExtension(const QString &extension);
    QString pattern();
private:
    QString _firstLetter;
    QString _code;
    QString _extension;
};

#endif // ROMREGEX_H
