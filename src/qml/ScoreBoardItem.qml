import QtQuick 2.0

Item {
    id: root;
    height: 80;
    property int mg: 10;
    property string name: "";
    property int score: 0;
    property int rank: 0;
    property bool isKA: false;

    Rectangle{
        id: rect;
        color: "transparent";
        border.color: "aqua";
        border.width: 3;
        x: mg;
        y: mg;
        width: parent.width - 2 * mg;
        height: parent.height - 2 * mg;
        radius: mg;

        Text{
            id: n_text;
            text: "#" + rank + " " + name;
            color: "white";
            font.family: "Arial";
            font.pixelSize: parent.height - 3.5 * mg;
            x: 1.5 * mg;
            anchors.verticalCenter: parent.verticalCenter;
        }

        Text{
            id: s_text;
            text: score;
            color: "white";
            font.family: "Arial";
            font.pixelSize: parent.height - 3.5 * mg;
            x: 1.5 * mg;
            anchors.verticalCenter: parent.verticalCenter;
            horizontalAlignment: Text.AlignRight;
            width: parent.width - 2 * x;
        }
    }

    Component.onCompleted: {
        if(isKA == true){
            rect.border.color = "lime";
        }
    }
}
