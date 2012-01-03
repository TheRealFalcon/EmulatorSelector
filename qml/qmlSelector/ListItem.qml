import QtQuick 1.0

Item {
    //id: item1
    property variant properties: model
    width: parent.width
    height: 20
    Keys.onReturnPressed: {onSelected()}
    Keys.onEnterPressed: {onSelected()}
    Text {
        color: "#ffffff"
        text: display
        width: parent.width
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
        onClicked: {onSelected()}
    }
    function onSelected() {
        currentList.focus = true
        if (currentList.currentIndex == index) {
            currentList.currentIndex = 0
        }
        else {
            currentList.currentIndex = index
        }
    }
}
