import QtQuick 1.0

//StupidGitTest

Rectangle {
    width: 800
    height: 600

    ListView {
        id: emulatorList
        width: 200
        height: parent.height
        transformOrigin: Item.Center
        model: emulatorModel
        delegate: emulatorDelegate
        highlight: Rectangle { color: "lightblue"; radius: 2; width: 200}
        focus: true

        Component {
            id: emulatorDelegate
            Text { text: name }

        }

        XmlListModel {
            id: emulatorModel
            source: "settings.xml"
            query: "/Selector/Emulator"
            XmlRole { name: "name"; query: "@name/string()" }
        }
    }

    ListView {
        id: standardCodesList
        width: 200
        height: parent.height
        x: emulatorList.width
        y: 0
        model: standardCodesModel
        delegate: standardCodesDelegate

        Component {
            id: standardCodesDelegate
            Text { text: standardItems }
        }

        XmlListModel {
            id: standardCodesModel
            source: "settings.xml"
            query: '/Selector/Code[@type="Standard"]/value'
            XmlRole { name: "standardItems"; query: 'string()' }
        }
    }

    ListView {
        id: countryCodesList
        width: 200
        height: parent.height
        x: emulatorList.width + emulatorList.width
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
