import QtQuick 2.0

Item {
    id: root;
    property int size: 100;
    property int int_id: 0;
    width: size;
    height: size;

    Rectangle {
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.verticalCenter: parent.verticalCenter;
        width: parent.width * 0.8;
        height: parent.height * 0.8;
        radius: width*0.5;
        color: "red";
    }
}
