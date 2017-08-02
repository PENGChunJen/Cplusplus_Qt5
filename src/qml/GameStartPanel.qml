import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    id: root;
    height: 240;
    width: 480;
    property var controlTimer: null;

    Rectangle{
        id: rect1;
        anchors.fill: parent;
        color: "black";
        radius: 30;
    }

    Rectangle{
        id: rect2;
        anchors.fill: parent;
        anchors.margins: 8;
        color: "transparent";
        radius: 30;
        border.color: "peru";
        border.width: 4;
    }

    Text{
        id: titleText;
        text: "Parking ROCK!!!";
        color: "cornsilk";
        font.family: "Arial Black";
        font.pixelSize: 44;
        anchors.horizontalCenter: parent.horizontalCenter;
        y: 42;
    }

    Rectangle{
        id: button;
        anchors.horizontalCenter: root.horizontalCenter;
        y: 132;
        height: 64;
        width: 180;
        border.color: "aqua";
        border.width: 3;
        color: "transparent";
        radius: 10;

        MouseArea {
            anchors.fill: parent;
            onClicked: {
                if(controlTimer != null){
                    controlTimer.running = true;
                }
                rect1.visible = false;
                rect2.visible = false;
                button.visible = false;
                titleText.visible = false;
                buttonText.visible = false;
            }
        }

        Text{
            id: buttonText;
            text: "Let's start!";
            color: "white";
            font.family: "Arial";
            font.pixelSize: 28;
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
        }
    }
}
