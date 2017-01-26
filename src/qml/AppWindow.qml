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
        objectName: "littleMap";
        w: map.w;
        h: map.h;
        blockSize: appWindow.blockSize;
        x: 0;
        y: 0;
    }

    Agent {
        id: agent;
        objectName: "agent";
        ax: map.ax;
        ay: map.ay;
        size: blockSize;
    }

}
