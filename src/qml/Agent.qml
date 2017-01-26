import QtQuick 2.0

Item {
    id: root;
    property int size: 100;
    property int ax: 0;
    property int ay: 0;
    x: ax * size;
    y: ay * size;
    width: size;
    height: size;

    signal move(int d);
    signal renewPos(int x, int y);

    onRenewPos: {
        ax = x;
        ay = y;
    }

    Rectangle {
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.verticalCenter: parent.verticalCenter;
        width: parent.width * 0.8;
        height: parent.height * 0.8;
        radius: width*0.5;
        color: "red";
    }

    focus: true;
    Keys.onPressed: {
        if (event.key === Qt.Key_Up) {
            move(3);
        } else if (event.key === Qt.Key_Down) {
            move(1);
        } else if (event.key === Qt.Key_Right) {
            move(0);
        } else if (event.key === Qt.Key_Left) {
            move(2);
        }
    }
}
