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

    function setFreeNumber(f){
        free = f;
        if(f === 0){
            icon.source = "qrc:///res/park_icon_gray.png";
        }else if(f <= 15){
            icon.source = "qrc:///res/park_icon_red.png";
        }
    }
}
