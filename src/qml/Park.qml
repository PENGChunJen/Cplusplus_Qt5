import QtQuick 2.0

Item {
    id: root;
    property int size: 100;
    property int int_id: 0;
    property string p_color: "aqua";
    width: size;
    height: size;

    Rectangle {
        anchors.fill: parent;
        color: p_color;
    }
}
