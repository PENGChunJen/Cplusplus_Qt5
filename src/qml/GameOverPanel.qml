import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    id: root;
    height: 240;
    width: 480;
    property var map: null;

    Rectangle{
        anchors.fill: parent;
        color: "black";
        radius: 30;
        border.color: "peru";
        border.width: 3;
        //width: parent.width;
        //height: parent.height;
    }

    Button {
        x: 10;
        y: 50;
        id: retry;
        text: "Retry";

        onClicked: {
            map.restart();
        }
    }

    Button {
        x: 70;
        y: 50;
        id: quit;
        text: "Quit";

        onClicked: {
            console.log("Quit!");
            Qt.quit();
        }
    }
}
