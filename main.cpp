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


//void MainWindow::on_emulatorView_selection_changed(const QItemSelection &selected, const QItemSelection &deselected)
//{

//    //Based on current implementation, I can't select/deselect more than one thing at once.
//    //Assertion is to insure it stays that way.
//    Q_ASSERT(selected.indexes().size() < 2);
//    Q_ASSERT(deselected.indexes().size() < 2);

//    if (!selected.isEmpty()) {
//        this->regex.extensions.append("\\" + emulatorModel->getEmulator(selected.indexes().at(0)).extension);
//    }
//    if (!deselected.isEmpty()) {
//        this->regex.extensions.removeOne("\\" + emulatorModel->getEmulator(deselected.indexes().at(0)).extension);
//    }

//    qDebug() << this->regex.pattern();
//    QRegExp regExp(this->regex.pattern(), Qt::CaseInsensitive, QRegExp::RegExp);
//    proxyModel->setFilterRegExp(regExp);
//}

//void MainWindow::on_codeView_selection_changed(const QItemSelection &selected, const QItemSelection &deselected)
//{
//    if (!selected.isEmpty()) {
//        Code code = selected.indexes().at(0).data(Qt::UserRole+1).value<Code>();
//        this->regex.codes.insert(code.delimiters, code.key);
//    }
//    if (!deselected.isEmpty()) {
//        Code code = deselected.indexes().at(0).data(Qt::UserRole+1).value<Code>();
//        this->regex.codes.remove(code.delimiters, code.key);
//    }

//    qDebug() << this->regex.pattern();

//    QRegExp regExp(this->regex.pattern(), Qt::CaseInsensitive, QRegExp::RegExp);
//    proxyModel->setFilterRegExp(regExp);
//}

//void MainWindow::on_letterView_selection_changed(const QItemSelection &selected, const QItemSelection &deselected)
//{
//    if (!selected.isEmpty()) {
//        this->regex.firstLetters.append(selected.indexes().at(0).data().toString());
//    }
//    if (!deselected.isEmpty()) {
//        this->regex.firstLetters.removeOne(deselected.indexes().at(0).data().toString());
//    }

//    qDebug() << this->regex.pattern();

//    QRegExp regExp(this->regex.pattern(), Qt::CaseInsensitive, QRegExp::RegExp);
//    proxyModel->setFilterRegExp(regExp);
//}

//void MainWindow::on_fileView_doubleClicked(QModelIndex index)
//{
//    int i = 0;
//    QString romFile = index.sibling(0, i++).data().value<QString>();
//    QString romDir = index.sibling(0, i++).data().value<QString>();
//    //QString romExt = index.sibling(0, i++).data().value<QString>();
//    QString romEmulatorExe = index.sibling(0, i++).data().value<QString>();
//    QString romArgs = index.sibling(0, i).data().value<QString>();
//    //qDebug() << romFile << romDir << romExt << romEmulatorExe << romArgs;
//    QProcess::execute(romEmulatorExe, QStringList() << romDir + "/" + romFile << romArgs);

//}


