import QtQuick 1.0

ListView {
    id: currentList
    height: parent.height
    highlight: Rectangle { color: "#0000ff"; radius: 2; }
    focus: true
    //currentIndex: 0
    delegate: Component {
        ListItem {}
    }

}
