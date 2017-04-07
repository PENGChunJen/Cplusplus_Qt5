import QtQuick 2.0

Item {
    id: root;
    property int size: 100;
    property int int_id: 0;
    property string owner: "";
    width: size;
    height: size;

    Text{
        text: owner;
        color: "white";
        font.family: "Arial";
        font.pixelSize: 18;
        anchors.horizontalCenter: parent.horizontalCenter;
        //anchors.verticalCenter: parent.verticalCenter;
        y: -20;
    }

    Rectangle {
        id: ring2;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.verticalCenter: parent.verticalCenter;
        width: parent.width * 0.8;
        height: parent.height * 0.8;
        radius: width * 0.5;
        color: "blue";
    }

    Rectangle {
        id: ring1;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.verticalCenter: parent.verticalCenter;
        width: parent.width * 0.6;
        height: parent.height * 0.6;
        radius: width*0.5;
        color: "aqua";
    }

    Rectangle {
        id: circle;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.verticalCenter: parent.verticalCenter;
        width: parent.width * 0.4;
        height: parent.height * 0.4;
        radius: width * 0.5;
        color: "black";
    }


    function setToKeyAgent(){
        ring1.color = "lime";
        ring2.color = "green";
    }
}
