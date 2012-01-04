import QtQuick 1.0

Rectangle {
    width: 800
    height: 600
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
            //currentIndex: 0

            XmlListModel {
                id: emulatorModel
                source: "settings.xml"
                query: "/Selector/Emulator"
                XmlRole { name: "display"; query: "@name/string()" }
                XmlRole { name: "extension"; query: "Extension/string()" }
            }

            onCurrentIndexChanged: {
                if (currentIndex < 1) {
                    romFilter.setEmulator("")
                }
                else {
                    //console.log(currentIndex);
                    romFilter.setEmulator(emulatorList.currentItem.properties.extension)
                }
            }
        }

        FilterList {
            id: standardCodesList
            width: parent.width / 6
            KeyNavigation.left: emulatorList
            KeyNavigation.right: countryCodesList
            model: standardCodesDisplayModel
            currentIndex: 0

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
                if (standardCodesList.currentIndex > 0) {
                    romFilter.addCodeFilter(standardCodesDelimiterModel.get(0).delimiter, standardCodesList.currentItem.properties.code)
                }
                if (countryCodesList.currentIndex > 0) {
                    romFilter.addCodeFilter(countryCodesDelimiterModel.get(0).delimiter, countryCodesList.currentItem.properties.code)
                }
            }
        }

        FilterList {
            id: countryCodesList
            width: parent.width / 6
            //position: 2
            model: countryCodesDisplayModel
            KeyNavigation.left: standardCodesList
            KeyNavigation.right: lettersList

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
                if (standardCodesList.currentIndex > 0) {
                    romFilter.addCodeFilter(standardCodesDelimiterModel.get(0).delimiter, standardCodesList.currentItem.properties.code)
                }
                if (countryCodesList.currentIndex > 0) {
                    romFilter.addCodeFilter(countryCodesDelimiterModel.get(0).delimiter, countryCodesList.currentItem.properties.code)
                }
            }
        }

        FilterList {
            id: lettersList
            width: parent.width / 20
            model: lettersModel
            KeyNavigation.left: countryCodesList
            KeyNavigation.right: romsList

            ListModel {
                id: lettersModel
            }

            onCurrentIndexChanged: {
                if (currentIndex < 1) {
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
            KeyNavigation.left: lettersList

            delegate: Component {
                ListItem {
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            currentList.focus = true
                            currentList.currentIndex = index
                        }
                        onDoubleClicked: {
                            onSelected()
                        }
                    }
                    function onSelected() {
                        romFilter.startRom(romsList.currentItem.properties.executable,
                                           romsList.currentItem.properties.directory,
                                           romsList.currentItem.properties.file,
                                           romsList.currentItem.properties.arguments)
                    }

                }
            }
        }
        //Arg...stupid xml model takes a few milliseconds longer to load and
        //puts the currentIndex at the last item loaded.
        //This is the only way I know to set the index to 0 after
        //the entire model is loaded.
        Timer {
            interval: 200; running: true; repeat: false
            onTriggered: setIndexes();
        }
    }

    function finishConstruction() {
        lettersModel.append({display: "Any"});
        var i
        for (i=65; i<91; i++) {
            lettersModel.append({display: String.fromCharCode(i)})
        }
    }

    function setIndexes() {
        emulatorList.currentIndex = 0;
        standardCodesList.currentIndex = 0;
        countryCodesList.currentIndex = 0;
    }

    Component.onCompleted: finishConstruction();
}
