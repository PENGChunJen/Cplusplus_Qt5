import QtQuick 2.0
import QtQuick.Controls 1.1

ApplicationWindow {
    id: appWindow;
    objectName: "appWindow";
    visible: true;

    Map {
        id: map;
        objectName: "map";
        h: channel.mw;
        w: channel.mh;
        blockSize: 720/channel.mw>720/channel.mh ? 720/channel.mh : 720/channel.mw;
        x: 0;
        y: 100;

        signal kbAgentMove(int d);

        Connections{
            target: channel;
            onQtDrawPark: map.drawPark(id, type, x, y, free);
            onQtDrawWall: map.drawWall(id, show, x, y);
            onQtDrawCar: map.drawCar(id, owner, x, y, isKeyAgent);
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

        interval: 100; running: true; repeat: true;
        onTriggered: run();
    }
}
