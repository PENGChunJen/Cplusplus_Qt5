import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    id: root;
    height: 300;
    width: 480;
    //property var map: null;
    property int kbRank: 0;
    property int kbScore: 0;

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

        Text{
            text: "Congratulations!"
                  + "<br> You got rank #" + kbRank
                  + "<br> and had total " + kbScore + " points!";
            color: "white";
            font.family: "Arial";
            font.pixelSize: 32;
            anchors.horizontalCenter: parent.horizontalCenter;
            y: 45;
        }
    }

    Rectangle{
        x: 264;
        y: 194;
        height: 64;
        width: 144;
        border.color: "aqua";
        border.width: 3;
        color: "transparent";
        radius: 10;

        Text{
            text: "Quit";
            color: "white";
            font.family: "Arial";
            font.pixelSize: 28;
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
        }

        MouseArea {
            anchors.fill: parent;
            onClicked: {
                Qt.quit();
            }
        }
    }
}
