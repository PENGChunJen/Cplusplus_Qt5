import QtQuick 2.0

Item {
    id: root;
    property int w: 3;
    property int h: 3;
    property int blockSize: 100;
    property var objects: [];
    width: w * blockSize;
    height: h * blockSize;

    Rectangle {
        anchors.fill: parent;
        color: "black";
    }
}

