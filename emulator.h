#ifndef EMULATOR_H
#define EMULATOR_H

#include <QtCore/QMetaType>

typedef struct struct_emulator {
    QString name;
    QString path;
    QString args;
    QString extension;
    QStringList searchPaths;
    //void saveSettings;
} Emulator;

Q_DECLARE_METATYPE(struct_emulator)

#endif // EMULATOR_H
