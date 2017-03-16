import QtQuick 2.0

Item {
    id: root;
    property int size: 100;
    property int int_id: 0;
    property string owner: "";
    width: size;
    height: size;

    Rectangle {
        id: circle;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.verticalCenter: parent.verticalCenter;
        width: parent.width * 0.8;
        height: parent.height * 0.8;
        radius: width*0.5;
        color: "red";
    }

    Text{
        text: owner;
        color: "white";
        font.family: "Times";
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.verticalCenter: parent.verticalCenter;
    }

    function setToKeyAgent(){
        circle.color = "lime";
    }
}
