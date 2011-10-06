import QtQuick 1.0

ListView {
    property int position
    id: currentList
    x: 200 * position
    width: 200
    height: parent.height
    highlight: Rectangle { color: "lightblue"; radius: 2; width: 200}
    focus: true
    currentIndex: -1

    Component {
        id: listViewDelegate
        Item {
            property variant properties: model
            width: parent.width; height: 20
            Text { text: display }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    currentList.currentIndex = index
                }
            }
        }
    }
}
