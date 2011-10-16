import QtQuick 1.0

ListView {
    property variant previousItem
    id: currentList
    width: parent.width / 4
    height: parent.height
    highlight: Rectangle { color: "#0000ff"; radius: 2; width: 200}
    focus: true
    currentIndex: -1
    //anchors.leftMargin: 10
    delegate: Component {
        Item {
            id: item1
            property variant properties: model
            width: parent.width
            height: 20
            Text {
                color: "#ffffff"
                text: display
                width: parent.width
                //text: parent.width
                clip: true
                wrapMode: Text.NoWrap
                style: Text.Raised
                font.pointSize: 12
                styleColor: "#030000"
                font.family: "Georgia"
                verticalAlignment: Text.AlignVCenter
            }
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
