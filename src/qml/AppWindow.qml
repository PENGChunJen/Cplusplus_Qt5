import QtQuick 2.0
import QtQuick.Controls 1.1

ApplicationWindow {
    id: appWindow;
    objectName: "appWindow";
    visible: true;
    //width: 300; height: 300;

    property int blockSize: 720/channel.mw>720/channel.mh ? 720/channel.mh : 720/channel.mw;
    signal move(int d);

    Map {
        id: littleMap;
        objectName: "littleMap";
        w: channel.mw;
        h: channel.mh;
        blockSize: appWindow.blockSize;
        x: 0;
        y: 0;
    }

    Agent {
        id: agent;
        objectName: "agent";
        ax: channel.ax;
        ay: channel.ay;
        size: blockSize;
    }

}
