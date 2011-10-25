import QtQuick 1.0

ListView {
    //property variant previousItem
    id: currentList

    height: parent.height
    highlight: Rectangle { color: "#0000ff"; radius: 2; }
    focus: true
    currentIndex: -1
    //anchors.leftMargin: 1

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
                focus: true
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
                    currentList.focus = true
                    //currentList.previousItem = properties
                    if (currentList.currentIndex == index) {                        
                        currentList.currentIndex = -1
                    }
                    else {
                        currentList.currentIndex = index
                    }
                }
                onDoubleClicked: {
                    console.log("Double clicked")
                    onSelected()
                }
                Keys.onPressed: {
                    console.log("Enter pressed")
                    onSelected()
                }
            }
        }
    }
}
