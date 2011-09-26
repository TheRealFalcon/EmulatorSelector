#ifndef ROM_H
#define ROM_H

#include <QtCore/QMetaType>
#include <QtCore/QString>

typedef struct rom_struct {
    QString file;
    QString directory;
    QString extension;
    QString executable;
    QString arguments;
} Rom;

Q_DECLARE_METATYPE(rom_struct)

#endif // ROM_H
