import QtQuick 2.0

Item {
    id: root;
    property int size: 100;
    property int int_id: 0;
    width: size;
    height: size;

    Rectangle {
        anchors.fill: parent;
        color: "aqua";
    }
}
