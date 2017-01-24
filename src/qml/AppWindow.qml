import QtQuick 2.0
import QtQuick.Controls 1.1

ApplicationWindow {
    id: appWindow;
    objectName: "appWindow";
    visible: true;
    //width: 300; height: 300;

    property int blockSize: 100;
    signal move(int d);

    Map {
        id: littleMap;
        property int w: map.w;
        property int h: map.h;
        width: blockSize * w;
        height: blockSize * h;
        x: 0;
        y: 0;

        Component.onCompleted: function(){
            var component = Qt.createComponent("Wall.qml");
            if (component.status == Component.Ready){
                component.createObject(littleMap, {"x": blockSize, "y": blockSize, "size": blockSize});
                component.createObject(littleMap, {"x": blockSize, "y": 3*blockSize, "size": blockSize});
                component.createObject(littleMap, {"x": 3*blockSize, "y": blockSize, "size": blockSize});
                component.createObject(littleMap, {"x": 3*blockSize, "y": 3*blockSize, "size": blockSize});
            }
        };
    }

    Agent {
        id: agent;
        objectName: "agent"
        ax: map.ax;
        ay: map.ay;
        size: blockSize;
    }

}
