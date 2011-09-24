#ifndef EMULATORMODEL_H
#define EMULATORMODEL_H

#include <include/settings.h>

class QStandardItemModel;
class QModelIndex;
class QString;

class EmulatorModel
{
private:
    QStandardItemModel *model;
    Settings *config;
public:
    EmulatorModel(Settings* config);
    QStandardItemModel* getModel();
    void addEmulator(Emulator emulator);
    Emulator getEmulator(QModelIndex index);
    void removeEmulator(QModelIndex index);
    void replaceEmulator(QModelIndex index, Emulator newEmulator);
    QModelIndex getFirstIndex();
    QModelIndex getLastIndex();
    QList<Emulator> emulatorList();
    ~EmulatorModel();

};

#endif // EMULATORMODEL_H
