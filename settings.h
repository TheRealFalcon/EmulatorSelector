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
    static const QString SETTINGS_FILE;
private:    
    QDomDocument* doc;
};

#endif // SETTINGS_H
