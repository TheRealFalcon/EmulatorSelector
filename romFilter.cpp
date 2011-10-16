#include "romFilter.h"
#include "romModel.h"
#include "romRegex.h"
#include "settings.h"
#include "emulator.h"

#include <QtGui/QSortFilterProxyModel>
#include <QtCore/QDir>
#include <QtCore/QDebug>

RomFilter::RomFilter(QObject* parent):
    QObject(parent)
{
    _model = new QSortFilterProxyModel();
    _model->setSourceModel(getRoms());
    _model->setFilterRole(RomModel::FileRole);
}

RomFilter::~RomFilter()
{
    delete _model;
}

QSortFilterProxyModel* RomFilter::model()
{
    return _model;
}

RomModel* RomFilter::getRoms()
{
    Settings settings;
    RomModel* romModel = new RomModel();
    foreach (Emulator emulator, settings.getEmulators()) {
        foreach (QString searchPath, emulator.searchPaths) {
            QDir dir(searchPath);
            QStringList searchFiles = dir.entryList(QStringList() << "*" + emulator.extension, QDir::Files);
            foreach (QString searchFile, searchFiles) {
                Rom newRom;
                newRom.file = searchFile;
                newRom.directory = searchPath;
                newRom.extension = emulator.extension;
                newRom.executable = emulator.path;
                newRom.arguments = emulator.args;
                romModel->addRom(newRom);
            }
        }
    }
    return romModel;
}

void RomFilter::setEmulator(const QString &emulatorExtension)
{
    _regex.setExtension(emulatorExtension);
    _model->setFilterRegExp(_regex.pattern());
}

void RomFilter::addCodeFilter(const QString &delimiter, const QString &code)
{
    _regex.setCode(delimiter, code);
    _model->setFilterRegExp(_regex.pattern());
}

void RomFilter::removeCodeFilter(const QString &delimiter, const QString &code)
{
    _regex.removeCode(delimiter, code);
    _model->setFilterRegExp(_regex.pattern());
}

void RomFilter::setLetter(const QString &firstLetter)
{
    _regex.setFirstLetter(firstLetter);
    _model->setFilterRegExp(_regex.pattern());
}

void RomFilter::startRom()
{
    //int i = 0;
    //QString romFile = index.sibling(0, i++).data().value<QString>();
    //QString romDir = index.sibling(0, i++).data().value<QString>();
    //QString romExt = index.sibling(0, i++).data().value<QString>();
    //QString romEmulatorExe = index.sibling(0, i++).data().value<QString>();
    //QString romArgs = index.sibling(0, i).data().value<QString>();
    //qDebug() << romFile << romDir << romExt << romEmulatorExe << romArgs;
    //QProcess::execute(romEmulatorExe, QStringList() << romDir + "/" + romFile << romArgs);
    qDebug() << "startRom called";
}

