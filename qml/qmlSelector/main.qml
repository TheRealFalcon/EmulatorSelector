import QtQuick 1.0

Rectangle {
    width: 800
    height: 600

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
        model: standardCodesDisplayModel

        XmlListModel {
            id: standardCodesDisplayModel
            source: "settings.xml"
            query: '/Selector/Code[@type="Standard"]/value'
            XmlRole { name: "display"; query: "string()" }
            XmlRole { name: "code"; query: "@key/string()" }
        }

        XmlListModel {
            id: standardCodesDelimiterModel
            source: "settings.xml"
            query: '/Selector/Code[@type="Standard"]'
            XmlRole { name: "delimiter"; query: "@delimiters/string()" }
        }

        onCurrentIndexChanged: {
            romFilter.onCodeSelectionChanged(standardCodesDelimiterModel.get(0).delimiter,
                                             standardCodesList.currentItem.properties.code)
        }
    }

    FilterList {
        id: countryCodesList
        position: 2
        model: countryCodesDisplayModel

        XmlListModel {
            id: countryCodesDisplayModel
            source: "settings.xml"
            query: '/Selector/Code[@type="Country"]/value'
            XmlRole { name: "display"; query: 'string()' }
            XmlRole { name: "code"; query: '@key/string()' }
        }

        XmlListModel {
            id: countryCodesDelimiterModel
            source: 'settings.xml'
            query: '/Selector/Code[@type="Country"]'
            XmlRole { name: "delimiter"; query: "@delimiters/string()" }
        }

        onCurrentIndexChanged: {
            romFilter.onCodeSelectionChanged(countryCodesDelimiterModel.get(0).delimiter,
                                             countryCodesList.currentItem.properties.code)
        }
    }

    FilterList {
        property string display: file
        id: romsList
        position: 3
        model: romModel

        //delegate: Component {
        //    id: romsDelegate
        //    Text { text: file }
        //}
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
