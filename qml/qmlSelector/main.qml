import QtQuick 1.0

Rectangle {
    width: 800
    height: 600



//    ListView {
//        id: emulatorList
//        width: 200
//        height: parent.height
//        transformOrigin: Item.Center
//        model: emulatorModel
//        highlight: Rectangle { color: "lightblue"; radius: 2; width: 200}
//        focus: true
//        currentIndex: -1

//        XmlListModel {
//            id: emulatorModel
//            source: "settings.xml"
//            query: "/Selector/Emulator"
//            XmlRole { name: "name"; query: "@name/string()" }
//            XmlRole { name: "extension"; query: "Extension/string()" }
//        }

//        delegate {
//            Item {
//                property variant properties: model
//                width: parent.width; height: 20
//                Text { text: name }
//                MouseArea {
//                    anchors.fill: parent
//                    onClicked: {
//                        emulatorList.currentIndex = index

//                    }
//                }
//            }
//        }
//        onCurrentIndexChanged: {
//            romFilter.onEmulatorSelectionChanged(emulatorList.currentItem.properties.extension)
//        }
//    }
    FilterList {
        id: emulatorList
        position: 0
        model: emulatorModel

        XmlListModel {
            id: emulatorModel
            source: "settings.xml"
            query: "/Selector/Emulator"
            XmlRole { name: "display"; query: "@name/string()" }
            XmlRole { name: "extension"; query: "Extension/string()" }
        }

        onCurrentIndexChanged: {
            romFilter.onEmulatorSelectionChanged(emulatorList.currentItem.properties.extension)
        }
    }

    FilterList {
        id: standardCodesList
        position: 1
        model: standardCodesModel

        XmlListModel {
            id: standardCodesModel
            source: "settings.xml"
            query: '/Selector/Code[@type="Standard"]/value'
            XmlRole { name: "display"; query: 'string()' }
        }

        onCurrentIndexChanged: {
            romFilter.onCodeSelectionChanged(standardCodesList.currentItem.properties.display)
        }
    }

//    ListView {
//        id: standardCodesList
//        width: 200
//        height: parent.height
//        x: emulatorList.width
//        y: 0
//        model: standardCodesModel
//        delegate: standardCodesDelegate

//        Component {
//            id: standardCodesDelegate
//            Text { text: standardItems }
//        }

//        XmlListModel {
//            id: standardCodesModel
//            source: "settings.xml"
//            query: '/Selector/Code[@type="Standard"]/value'
//            XmlRole { name: "standardItems"; query: 'string()' }
//        }
//    }

    ListView {
        id: countryCodesList
        width: 200
        height: parent.height
        x: emulatorList.width + standardCodesList.width
        y: 0
        model: countryCodesModel
        delegate: countryCodesDelegate

        Component {
            id: countryCodesDelegate
            Text { text: countryItems }
        }

        XmlListModel {
            id: countryCodesModel
            source: "settings.xml"
            query: '/Selector/Code[@type="Country"]/value'
            XmlRole { name: "countryItems"; query: 'string()' }
        }
    }

    ListView {
        id: romsList
        width: 200
        height: parent.height
        x: emulatorList.width + standardCodesList.width + countryCodesList.width
        y: 0
        model: romModel

        delegate: Component {
            id: romsDelegate
            Text { text: file }
        }
    }


}

// Q_INVOKABLE void AppHelper::write(QString path, QString data)
//{
//    QFile file( path );
//    file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
//    QTextStream out(&file);
//    out << data;
//    file.close();
//}

//...in main.cpp...
//    AppHelper *appHelper = new AppHelper();
//    view.rootContext()->setContextProperty("helper", appHelper);

//...in QML...
//    ...
//    var xml = Script.getXmlStart();
//    window.path = "trail_" + dateStamp + ".gpx";
//    helper.write(window.path, xml);
