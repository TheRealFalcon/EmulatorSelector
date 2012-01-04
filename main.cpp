#include <QtCore/QVariant>
#include <QtDeclarative/QDeclarativeContext>
#include <QtDeclarative/QDeclarativeView>
#include <QtGui/QApplication>
#include <QtGui/QIcon>
//#include "qmlapplicationviewer.h"
#include "romModel.h"
#include "settings.h"
#include "rom.h"
#include "romFilter.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QIcon appIcon(":/images/Cute_Ball_Games.png");
    app.setWindowIcon(appIcon);
    QDeclarativeView view;

    RomFilter filter; // = new RomFilter();
    view.rootContext()->setContextProperty("romModel", filter.model());
    view.rootContext()->setContextProperty("romFilter", &filter);
    //viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    view.setSource(QUrl("qrc:/qml/qmlSelector/main.qml"));
    view.show();

    return app.exec();
}





