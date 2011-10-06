#include "romRegex.h"

RomRegex::RomRegex()
{
    _firstLetter = "";
    _code = "";
    _extension = "";
}

QString RomRegex::pattern()
{
    QString pattern = "^";

    //First character set
    pattern += _firstLetter;

    //body
    pattern += ".*";

    pattern += _code;

    //Anything else before ext
    pattern += ".*";

    //extension
    pattern += _extension;

    pattern += "$";
    return pattern;
}

void RomRegex::setFirstLetter(const QString &firstLetter)
{
    _firstLetter = firstLetter;
}

void RomRegex::setCode(const QString &code)
{
    _code = code;
}

void RomRegex::setExtension(const QString &extension)
{
    _extension = extension;
}
