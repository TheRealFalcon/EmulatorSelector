#ifndef SETTINGS_H
#define SETTINGS_H

#include <QtCore/QList>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QMap>
#include <QtCore/QMetaType>

class QDomDocument;
class QDomElement;

typedef struct struct_emulator {
    QString name;
    QString path;
    QString args;
    QString extension;
    QStringList searchPaths;
    //void saveSettings;
} Emulator;

Q_DECLARE_METATYPE(struct_emulator)

typedef struct struct_code {
    QString type;
    QString delimiters;
    QString key;
    QString value;
} Code;

Q_DECLARE_METATYPE(struct_code)

class Settings
{
public:
    Settings();
    ~Settings();
    QStringList getCodeTypes();
    QList<Code> getCodes(QString codeType);
    QList<Emulator> getEmulators();
    void addEmulator(Emulator newEm);
    void removeEmulator(QString name);
    void replaceEmulator(QString oldName, Emulator newEm);

private:
    static const QString CONFIG_FILE;
    QDomDocument* doc;
    void writeChanges();
    QDomElement emulatorToElement(Emulator em);
};



#endif // SETTINGS_H
