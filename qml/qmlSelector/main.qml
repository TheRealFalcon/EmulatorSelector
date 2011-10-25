import QtQuick 1.0

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
    focus: true
   // transformOrigin: Item.Center

    Row {
        focus: true
        spacing: 10
        width: parent.width
        height: parent.height

        FilterList {
            id: emulatorList
            width: parent.width / 6
            KeyNavigation.right: standardCodesList
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
            width: parent.width / 6
            KeyNavigation.left: emulatorList
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
                romFilter.clearCodeFilter()
                if (standardCodesList.currentIndex > -1) {
                    romFilter.addCodeFilter(standardCodesDelimiterModel.get(0).delimiter, standardCodesList.currentItem.properties.code)
                }
                if (countryCodesList.currentIndex > -1) {
                    romFilter.addCodeFilter(countryCodesDelimiterModel.get(0).delimiter, countryCodesList.currentItem.properties.code)
                }
            }
        }

        FilterList {
            id: countryCodesList
            width: parent.width / 6
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
                romFilter.clearCodeFilter()
                if (standardCodesList.currentIndex > -1) {
                    romFilter.addCodeFilter(standardCodesDelimiterModel.get(0).delimiter, standardCodesList.currentItem.properties.code)
                }
                if (countryCodesList.currentIndex > -1) {
                    romFilter.addCodeFilter(countryCodesDelimiterModel.get(0).delimiter, countryCodesList.currentItem.properties.code)
                }
            }
        }

        FilterList {
            id: lettersList
            width: parent.width / 20
            model: lettersModel

            ListModel {
                id: lettersModel
            }

            onCurrentIndexChanged: {
                if (currentIndex < 0) {
                    romFilter.setLetter("")
                }
                else {
                    romFilter.setLetter(lettersList.currentItem.properties.display)
                }
            }
        }

        FilterList {
            id: romsList
            width: parent.width / 2
            model: romModel
            Keys.onEnterPressed: {
                console.log("Enter was pressed")
                onSelected()
            }

        function onSelected() {
            romFilter.startRom(romsList.currentItem.properties.executable,
                               romsList.currentItem.properties.directory,
                               romsList.currentItem.properties.file,
                               romsList.currentItem.properties.arguments)
            }
        }
    }

    function makeLetters() {
        var i
        for (i=65; i<91; i++) {
            lettersModel.append({display: String.fromCharCode(i)})
        }
    }

    Component.onCompleted: makeLetters();
}
