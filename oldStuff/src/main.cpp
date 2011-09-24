#include <QtGui/QApplication>
#include "include/mainwindow.h"
#include "include/emulatorModel.h"
#include "include/emulatorConfig.h"
#include "include/filterConfig.h"
#include "include/globalConfig.h"
#include "include/settings.h"
#include <QtCore/QDebug>
#include <QtCore/QList>
#include <QtGui/QStandardItemModel>
#include <QtGui/QStandardItem>

#include "include/test.h"
void testSettings()
{
    Settings config;
//    QList<Code> codes = config.getCodes();
//    foreach (Code code, codes) {
//        qDebug() << code.type;
//        foreach (QString key, code.values.keys()) {
//            qDebug() << key;
//        }
//        foreach (QString value, code.values.values()) {
//            qDebug() << value;
//        }
//    }

    QList<Emulator> emulators = config.getEmulators();
    foreach (Emulator em, emulators) {
        qDebug() << em.name;
        qDebug() << em.args;
        qDebug() << em.path;
        qDebug() << em.extension;
        foreach (QString path, em.searchPaths) {
            qDebug() << path;
        }
    }
}

int main(int argc, char *argv[])
{
    Settings *config = new Settings();
    EmulatorModel *emulatorModel = new EmulatorModel(config);

    QApplication a(argc, argv);

    MainWindow w(config, emulatorModel);
    //Test w;
    w.show();
    return a.exec();


//    testSettings();
//    return 0;
}


