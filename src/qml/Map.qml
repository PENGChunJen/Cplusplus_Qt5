import QtQuick 2.0

Item {
    id: root;
    property int w: 3;
    property int h: 3;
    property int blockSize: 100;
    width: blockSize * w;
    height: blockSize * h;

    signal buildWalls(int x, int y);
    onBuildWalls: {
        var component = Qt.createComponent("Wall.qml");
        if (component.status == Component.Ready){
            component.createObject(littleMap, {"x": x*blockSize, "y": y*blockSize, "size": blockSize});
        }
    }

    Rectangle {
        anchors.fill: parent;
        color: "black";
    }
}

