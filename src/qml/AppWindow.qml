import QtQuick 2.0
import QtQuick.Controls 2.1

ApplicationWindow {
    id: appWindow;
    objectName: "appWindow";
    visible: true;

    Connections{
        target: channel;
        onQtSBRenew: scoreboard.renew(id, rank, name, score, isKeyAgent);
        onQtDrawPark: map.drawPark(id, type, x, y, free);
        onQtDrawWall: map.drawWall(id, show, x, y);
        onQtDrawCar: map.drawCar(id, owner, x, y, isKeyAgent);
        onQtGameTerminate: {
            gameTimer.running = false;
        }
    }

    ScoreBoard{
        id: scoreboard;
        x: map.width;
        y: 0;
        height: map.height;
    }

    Map {
        id: map;
        objectName: "map";
        x_max: channel.mh;
        y_max: channel.mw;
        blockSize: Math.floor(205/y_max) * 5;
        x: 0;
        y: 0;

        signal kbAgentMove(int d);

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

        interval: 100;
        running: true;
        repeat: true;
        onTriggered: run();
    }

    Popup{
        id: gameoverPopup;
        x: 100;
        y: 100;
        width: 200;
        height: 300;
        modal: true;
        focus: true;
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent;
    }
}
