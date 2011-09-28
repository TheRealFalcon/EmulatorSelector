#ifndef SETTINGS_H
#define SETTINGS_H

#include "emulator.h"

class QDomDocument;

class Settings
{
public:
    Settings();
    ~Settings();
    QList<Emulator> getEmulators();
private:
    static const QString CONFIG_FILE;
    QDomDocument* doc;
};

#endif // SETTINGS_H
