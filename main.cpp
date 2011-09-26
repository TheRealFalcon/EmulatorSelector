#include <QtGui/QApplication>
#include <QtGui/QSortFilterProxyModel>
#include <QtDeclarative/QDeclarativeContext>
#include "qmlapplicationviewer.h"
#include "romModel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QmlApplicationViewer viewer;

    QSortFilterProxyModel *model = new QSortFilterProxyModel();
    model->setSourceModel(new RomModel());
    viewer.rootContext()->setContextProperty("romListModel", model);

    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/qmlSelector/main.qml"));
    viewer.showExpanded();



    return app.exec();
}


