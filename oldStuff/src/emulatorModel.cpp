#include "include/emulatorModel.h"
#include "include/settings.h"

#include <QtGui/QStandardItemModel>
#include <QtGui/QStandardItem>
#include <QtCore/QModelIndex>

#include <QDebug>

EmulatorModel::EmulatorModel(Settings *config)
{
    this->config = config;
    this->model = new QStandardItemModel();
    QList<Emulator> emulators = config->getEmulators();
    foreach (Emulator emulator, emulators) {
         QStandardItem *emulatorItem = new QStandardItem();
         emulatorItem->setData(qVariantFromValue(emulator));
         emulatorItem->setText(emulator.name);
         this->model->appendRow(emulatorItem);
    }
}

void EmulatorModel::addEmulator(Emulator emulator)
{
    QStandardItem *newRow = new QStandardItem(emulator.name);
    newRow->setData(qVariantFromValue(emulator));
    model->appendRow(newRow);
    config->addEmulator(emulator);
}

void EmulatorModel::removeEmulator(QModelIndex index)
{
    QString name = model->data(index, Qt::DisplayRole).value<QString>();
    config->removeEmulator(name);
    model->removeRow(index.row());
}

void EmulatorModel::replaceEmulator(QModelIndex index, Emulator newEmulator)
{
    Emulator originalEmulator = model->data(index, Qt::UserRole+1).value<Emulator>();
    QString originalName = originalEmulator.name;
    model->setData(index, qVariantFromValue(newEmulator), Qt::UserRole+1);
    model->setData(index, newEmulator.name, Qt::DisplayRole);
    config->replaceEmulator(originalName, newEmulator);
}

QStandardItemModel* EmulatorModel::getModel()
{
    return model;
}

QModelIndex EmulatorModel::getFirstIndex()
{
    return model->index(0, 0);
}

QModelIndex EmulatorModel::getLastIndex()
{
    return model->index(model->rowCount()-1, 0);
}

Emulator EmulatorModel::getEmulator(QModelIndex index)
{
    return model->data(index, Qt::UserRole+1).value<Emulator>();
}

QList<Emulator> EmulatorModel::emulatorList()
{
    QList<Emulator> emulatorList;
    for (int i=0; i<model->rowCount(); i++) {
        QModelIndex index = model->index(i, 0);
        emulatorList.append(model->data(index, Qt::UserRole+1).value<Emulator>());
    }
    return emulatorList;
}

EmulatorModel::~EmulatorModel()
{
    delete model;
}

