#include "include/settings.h"
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include <QtCore/QStringList>
#include <QtCore/QFile>
#include <QtCore/QPair>
#include <QtCore/QDebug>

const QString Settings::CONFIG_FILE = "etc/settings.xml";

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

QStringList Settings::getCodeTypes()
{
    QStringList codeTypes;
    for (QDomElement codeType = doc->firstChildElement().firstChildElement("Code"); !codeType.isNull(); codeType = codeType.nextSiblingElement("Code")) {
        codeTypes.append(codeType.attribute("type"));
    }
    return codeTypes;
}

QList<Code> Settings::getCodes(QString codeType)
{
    QList<Code> codes;
    for (QDomElement codeElement = doc ->firstChildElement().firstChildElement("Code"); !codeElement.isNull(); codeElement = codeElement.nextSiblingElement("Code")) {
        if (codeElement.attribute("type") == codeType) {
            for (QDomElement valueElement = codeElement.firstChildElement("value"); !valueElement.isNull(); valueElement = valueElement.nextSiblingElement("value")) {
                Code newCode;
                newCode.type = codeElement.attribute("type");
                newCode.delimiters = codeElement.attribute("delimiters");
                newCode.key = valueElement.attribute("key");
                newCode.value = valueElement.text();
                codes.append(newCode);
            }
        }
    }
    return codes;
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

void Settings::addEmulator(Emulator newEm)
{
    QDomElement emElement = emulatorToElement(newEm);
    QDomElement topElement = doc->firstChildElement();
    QDomElement lastEmulator = topElement.lastChildElement("Emulator");
    if (lastEmulator.isNull()) {
        lastEmulator = topElement.lastChildElement("Code");
    }
    topElement.insertAfter(emElement, lastEmulator);
    writeChanges();
}

void Settings::removeEmulator(QString name)
{
    QDomNodeList emulatorNodes = doc->elementsByTagName("Emulator");
    for (int i=0; i<emulatorNodes.size(); i++) {
        QDomElement emulatorElement = emulatorNodes.at(i).toElement();
        if (emulatorElement.attribute("name") == name) {
            doc->firstChild().removeChild(emulatorElement);
        }
    }
    writeChanges();
}

void Settings::replaceEmulator(QString oldName, Emulator newEm)
{
    QDomElement emElement = emulatorToElement(newEm);

    QDomNodeList emulatorNodes = doc->elementsByTagName("Emulator");
    for (int i=0; i<emulatorNodes.size(); i++) {
        QDomElement oldElement = emulatorNodes.at(i).toElement();
        if (oldElement.attribute("name") == oldName) {
            doc->firstChild().replaceChild(emElement, oldElement);
        }
    }
    writeChanges();
}

QDomElement Settings::emulatorToElement(Emulator newEm)
{
    QDomElement emElement = doc->createElement("Emulator");
    emElement.setAttribute("name", newEm.name);

    QDomElement newElement;
    newElement = doc->createElement("Path");
    newElement.appendChild(doc->createTextNode(newEm.path));
    emElement.appendChild(newElement);

    newElement = doc->createElement("Args");
    newElement.appendChild(doc->createTextNode(newEm.args));
    emElement.appendChild(newElement);

    newElement = doc->createElement("Extension");
    newElement.appendChild(doc->createTextNode(newEm.extension));
    emElement.appendChild(newElement);

    QDomElement searchElement = doc->createElement("Search");
    foreach (QString searchDir, newEm.searchPaths) {
        newElement = doc->createElement("dir");
        newElement.appendChild(doc->createTextNode(searchDir));
        searchElement.appendChild(newElement);
    }
    emElement.appendChild(searchElement);
    return emElement;
}

void Settings::writeChanges()
{
    QFile outFile(CONFIG_FILE);
    if(!outFile.open(QIODevice::WriteOnly | QIODevice::Text )) {
        qDebug( "Failed to open file for writing." );
        return;
    }

    QTextStream stream( &outFile );
    stream << doc->toString(2);

    outFile.close();
}

