#include <QtCore/QStringList>
#include <QtCore/QFile>
#include <QtCore/QList>
#include <QtCore/QDebug>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include "settings.h"

const QString Settings::CONFIG_FILE = "settings.xml";

Settings::Settings()
{
    doc = new QDomDocument();
    QFile file(CONFIG_FILE);
    if (!file.open(QIODevice::ReadWrite)) {
        qDebug() << "Couldn't open file";
        return;
    }
    if (!doc->setContent(&file)) {
        qDebug() << "Couldn't set content";
        file.close();
        return;
    }
    file.close();

}

Settings::~Settings()
{
    delete doc;
}

QList<Emulator> Settings::getEmulators()
{
    QList<Emulator> emulators;
    for (QDomElement emulatorElement = doc ->firstChildElement().firstChildElement("Emulator"); !emulatorElement.isNull(); emulatorElement = emulatorElement.nextSiblingElement("Emulator")) {
        Emulator newEmulator;
        newEmulator.name = emulatorElement.attribute("name");
        newEmulator.path= emulatorElement.firstChildElement("Path").text();
        newEmulator.args = emulatorElement.firstChildElement("Args").text();
        newEmulator.extension = emulatorElement.firstChildElement("Extension").text();
        for (QDomElement dirElement = emulatorElement.firstChildElement("Search").firstChildElement("dir"); !dirElement.isNull(); dirElement = dirElement.nextSiblingElement("dir")) {
            newEmulator.searchPaths.append(dirElement.text());
        }
        emulators.append(newEmulator);
    }

    return emulators;
}
