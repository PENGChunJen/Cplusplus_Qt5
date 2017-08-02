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
    }

    Rectangle{
        anchors.fill: parent;
        anchors.margins: 8;
        color: "black";
        radius: 30;
        border.color: "peru";
        border.width: 4;
    }

    Rectangle{
        id: button;
        x: 264;
        y: 132;
        height: 64;
        width: 144;
        border.color: "aqua";
        border.width: 3;
        color: "transparent";
        radius: 10;

        MouseArea {
            anchors.fill: parent;
            onClicked: {
                console.log("Quit!");
                Qt.quit();
            }
        }

        Text{
            id: buttonText;
            text: "Quit";
            color: "white";
            font.family: "Arial";
            font.pixelSize: 28;
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
        }
    }
}
