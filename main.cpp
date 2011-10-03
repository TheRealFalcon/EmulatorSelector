#include <QtGui/QApplication>
#include <QtDeclarative/QDeclarativeContext>
#include <QtCore/QVariant>
#include "qmlapplicationviewer.h"
#include "romModel.h"
#include "settings.h"
#include "rom.h"
#include "romFilter.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QmlApplicationViewer viewer;



    RomFilter filter; // = new RomFilter();
    viewer.rootContext()->setContextProperty("romModel", filter.model());
    viewer.rootContext()->setContextProperty("romFilter", &filter);
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/qmlSelector/main.qml"));
    viewer.showExpanded();



    return app.exec();
}





