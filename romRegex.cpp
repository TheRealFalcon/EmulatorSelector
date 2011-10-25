#include "romRegex.h"

#include <QtCore/QStringList>
#include <QtCore/QDebug>

RomRegex::RomRegex()
{
    _firstLetter = "";
    //_codes = "";
    _extension = "";
}

QString RomRegex::pattern()
{
    QString pattern = "^";

    //First character set
    if (!_firstLetter.isEmpty()) {
        pattern += '(' + _firstLetter + '|' + QChar(_firstLetter.at(0).toAscii() + 32) + ')';
    }

    //body
    pattern += ".*";

    foreach (QString delimiter, _codes.uniqueKeys()) {
        Q_ASSERT(delimiter.size() == 2);
        QString codeStart = QString(delimiter.at(0));
        QString codeEnd = QString(delimiter.at(1));
        QStringList codeValues(_codes.values(delimiter));
        pattern += "\\" + codeStart + "(" + codeValues.join("|") + ")\\" + codeEnd;
        pattern += ".*";
    }

    //Anything else before ext
    //pattern += ".*";

    //extension
    pattern += _extension;

    pattern += "$";
    qDebug() << pattern;
    return pattern;
}

void RomRegex::setFirstLetter(const QString &firstLetter)
{
    _firstLetter = firstLetter;
}

void RomRegex::setCode(const QString &delimiter, const QString &code)
{
    _codes.insert(delimiter, code);
}

void RomRegex::removeCode(const QString &delimiter, const QString &code)
{
    _codes.remove(delimiter, code);
}

void RomRegex::removeCodes()
{
    _codes.clear();
}

void RomRegex::setExtension(const QString &extension)
{
    _extension = extension;
}
