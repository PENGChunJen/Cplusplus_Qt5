import QtQuick 2.0

Item {
    id: root;
    property int size: 100;
    property int int_id: 0;
    property int free: 0;
    width: size;
    height: size;

    Image {
        id: icon;
        anchors.fill: parent;
        source: "qrc:///res/park_icon.png";
    }

    Text{
        text: free;
        color: "papayawhip";
        font.family: "Arial Black";
        font.pixelSize: size / 3;
        //anchors.horizontalCenter: parent.horizontalCenter;
        //anchors.verticalCenter: parent.verticalCenter;
        x: size / 1.8;
        y: size / 1.8;
    }

    function setFreeNumber(f){
        free = f;
        if(f === 0){
            icon.source = "qrc:///res/park_icon_gray.png";
        }else if(f <= 15){
            icon.source = "qrc:///res/park_icon_red.png";
        }
    }
}
