import Qt 4.7

Item {
    width: 500; height: 250

    XmlListModel {
        id: emulatorModel
        source: "settings.xml"
        query: "/Selector/Emulator"
        XmlRole { name: "name"; query: "@name/string()" }
    }

    XmlListModel {
        id: codeModel
        source: "settings.xml"
        query: "/Selector/Code"
        XmlRole { name: "title"; query: "value/string()" }
    }


    Component {
        id: emulatorDelegate
        Text { text: name }
    }

    Component {
        id: codeDelegate
        Text { text: title }
    }

    ListView {
        anchors.fill: parent
        model: emulatorModel
        delegate: emulatorDelegate
    }

    ListView {
        anchors.fill: parent
        model: codeModel
        delegate: codeDelegate
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
