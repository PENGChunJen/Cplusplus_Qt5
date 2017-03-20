import QtQuick 2.0

Item {
    id: root;
    property int size: 100;
    property int int_id: 0;
    property int free: 0;
    width: size;
    height: size;

    Rectangle {
        id: square;
        anchors.fill: parent;
        color: "aqua";
    }

    Text{
        text: free.toString();
        color: "black";
        font.family: "Times";
        font.pointSize: size/3;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.verticalCenter: parent.verticalCenter;
    }

    function setFreeNumber(f){
        free = f;
        if(f === 0){
            square.color = "slategray";
        }
    }
}
