#include <QtCore/QVariant>
#include <QtDeclarative/QDeclarativeContext>
#include <QtDeclarative/QDeclarativeView>
#include <QtGui/QApplication>
#include <QtGui/QIcon>
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
    view.rootContext()->setContextProperty("SETTINGS_FILE", QString(Settings::SETTINGS_FILE));
    //viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    view.setSource(QUrl("qrc:/qml/main.qml"));
    view.show();

    return app.exec();
}





