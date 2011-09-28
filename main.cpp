#include <QtGui/QApplication>
#include <QtGui/QSortFilterProxyModel>
#include <QtDeclarative/QDeclarativeContext>
#include <QtCore/QDir>
#include "qmlapplicationviewer.h"
#include "romModel.h"
#include "settings.h"
#include "rom.h"

RomModel* getRoms()
{
    Settings settings;
    QList<Emulator> emulators = settings.getEmulators();

    RomModel* romModel = new RomModel();
    //romModel->appendRow(new QStandardItem("Hello"));
    foreach (Emulator emulator, emulators) {
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
//                QStandardItem *fileItem = new QStandardItem(searchFile);
//                QStandardItem *directoryItem = new QStandardItem(searchPath);
//                QStandardItem *extensionItem = new QStandardItem(emulator.extension);
//                QStandardItem *exeItem = new QStandardItem(emulator.path);
//                QStandardItem *argsItem = new QStandardItem(emulator.args);
//                QList<QStandardItem*> row;
//                row << fileItem << directoryItem << extensionItem << exeItem << argsItem;
//                romModel->appendRow(row);
            }
        }
    }
    return romModel;
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QmlApplicationViewer viewer;

    QSortFilterProxyModel *model = new QSortFilterProxyModel();
    model->setSourceModel(getRoms());
    viewer.rootContext()->setContextProperty("romModel", model);

    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/qmlSelector/main.qml"));
    viewer.showExpanded();



    return app.exec();
}


