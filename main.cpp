#include <QtGui/QApplication>
#include <QtGui/QSortFilterProxyModel>
#include <QtDeclarative/QDeclarativeContext>
#include "qmlapplicationviewer.h"
#include "romModel.h"
#include "settings.h"

void getRoms()
{
    //    QStandardItemModel *fileModel = new QStandardItemModel();
    //    fileModel->appendRow(new QStandardItem("Hello"));
    //    foreach (Emulator emulator, emulatorModel->emulatorList()) {
    //        foreach (QString searchPath, emulator.searchPaths) {
    //            QDir dir(searchPath);
    //            QStringList searchFiles = dir.entryList(QStringList() << "*" + emulator.extension, QDir::Files);
    //            foreach (QString searchFile, searchFiles) {
    //                QStandardItem *fileItem = new QStandardItem(searchFile);
    //                QStandardItem *directoryItem = new QStandardItem(searchPath);
    //                QStandardItem *extensionItem = new QStandardItem(emulator.extension);
    //                QStandardItem *exeItem = new QStandardItem(emulator.path);
    //                QStandardItem *argsItem = new QStandardItem(emulator.args);
    //                QList<QStandardItem*> row;
    //                row << fileItem << directoryItem << extensionItem << exeItem << argsItem;
    //                fileModel->appendRow(row);
    //            }
    //        }
    //    }
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    getEmulators();

    QmlApplicationViewer viewer;

    QSortFilterProxyModel *model = new QSortFilterProxyModel();
    model->setSourceModel(new RomModel());
    viewer.rootContext()->setContextProperty("romModel", model);

    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/qmlSelector/main.qml"));
    viewer.showExpanded();



    return app.exec();
}


