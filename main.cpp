#include <QtGui/QApplication>
#include <QtDeclarative/QDeclarativeContext>
#include "qmlapplicationviewer.h"
#include "rom.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QmlApplicationViewer viewer;

    Rom *rom = new Rom();
    viewer.rootContext()->setContextProperty("romListModel", rom);
    //QStringList dataList;
    //dataList.append("Abc");
    //viewer.rootContext()->setContextProperty("romListModel", dataList);

    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/qmlSelector/main.qml"));
    viewer.showExpanded();



    return app.exec();
}


