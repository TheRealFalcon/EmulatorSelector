import QtQuick 1.0

ListView {
    property int position
    property variant previousItem
    id: currentList
    x: 200 * position
    width: 200
    height: parent.height
    highlight: Rectangle { color: "lightblue"; radius: 2; width: 200}
    focus: true
    currentIndex: -1
    delegate: Component {
        Item {
            property variant properties: model
            width: parent.width; height: 20
            Text { text: display }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if (currentList.currentIndex == index) {
                        currentList.previousItem = properties
                        currentList.currentIndex = -1
                    }
                    else {
                        currentList.currentIndex = index
                    }
                }
            }
        }
    }
}
