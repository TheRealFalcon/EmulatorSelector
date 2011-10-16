import QtQuick 1.0

//Rectangle {
//    width: 800
//    height: 600
Rectangle {
    width: 800
    height: 600
    //anchors.leftMargin: 20
    radius: 0
    gradient: Gradient {
        GradientStop {
            position: 0
            color: "#4b4b4b"
        }

        GradientStop {
            position: 1
            color: "#2d2c2c"
        }
    }
    clip: false
    smooth: false
   // transformOrigin: Item.Center

    Row {
        spacing: 10
        width: parent.width
        height: parent.height
        FilterList {
            id: emulatorList
            //position: 0
            model: emulatorModel

            XmlListModel {
                id: emulatorModel
                source: "settings.xml"
                query: "/Selector/Emulator"
                XmlRole { name: "display"; query: "@name/string()" }
                XmlRole { name: "extension"; query: "Extension/string()" }
            }

            onCurrentIndexChanged: {
                if (currentIndex < 0) {
                    romFilter.setEmulator("")
                }
                else {
                    romFilter.setEmulator(emulatorList.currentItem.properties.extension)
                }
            }
        }

        FilterList {
            id: standardCodesList
            //position: 1
            model: standardCodesDisplayModel
            //anchors.left: emulatorList.right

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
                if (currentIndex < 0) {
                    romFilter.removeCodeFilter(standardCodesDelimiterModel.get(0).delimiter, previousItem.code)
                }
                else {
                    romFilter.addCodeFilter(standardCodesDelimiterModel.get(0).delimiter,
                                                     standardCodesList.currentItem.properties.code)
                }
            }
        }

        FilterList {
            id: countryCodesList
            //position: 2
            model: countryCodesDisplayModel
            //anchors.left: standardCodesList.right

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
                if (currentIndex < 0) {
                    romFilter.removeCodeFilter(countryCodesDelimiterModel.get(0).delimiter, previousItem.code)
                }
                else {
                    romFilter.addCodeFilter(countryCodesDelimiterModel.get(0).delimiter,
                                                     countryCodesList.currentItem.properties.code)
                }
            }
        }

        FilterList {
            id: romsList
            //position: 3
            model: romModel
            //anchors.left: countryCodesList.right
        }
    }
}
