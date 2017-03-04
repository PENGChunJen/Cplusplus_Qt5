import QtQuick 2.0
import QtQuick.Controls 1.1

ApplicationWindow {
    id: appWindow;
    objectName: "appWindow";
    visible: true;

    Map {
        id: map;
        objectName: "map";
        w: channel.mw;
        h: channel.mh;
        blockSize: 720/channel.mw>720/channel.mh ? 720/channel.mh : 720/channel.mw;
        x: 0;
        y: 0;

        signal kbAgentMove(int d);

        Connections{
            target: channel;
            onQtDrawObject: map.drawObject(id, type, x, y);
            onRegisterKbAgent: map.registerKbAgent(id, x, y);
            onSetParkEmpty: map.objects[id].p_color = "slategray";
        }

        focus: true;
        Keys.onPressed: {
            if (event.key == Qt.Key_Down) {
                kbAgentMove(1);
            }else if (event.key == Qt.Key_Right) {
                kbAgentMove(2);
            }else if (event.key == Qt.Key_Up) {
                kbAgentMove(3);
            }else if (event.key == Qt.Key_Left) {
                kbAgentMove(4);
            }
            event.accepted = true;
        }
    }

    Timer{
        id: gameTimer;
        objectName: "timer";
        signal run();

        interval: 200; running: true; repeat: true;
        onTriggered: run();
    }
}
