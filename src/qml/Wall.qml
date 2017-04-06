import QtQuick 2.0

Item {
    id: root;
    property int size: 100;
    property int int_id: 0;
    property int show: 15;
    property real blockWidth: 0.6;
    property real edgeRadius: 0.2;
    width: size;
    height: size;

    Rectangle {
        id: main;
        color: "peru";
        x: parent.width * (1-blockWidth) / 2
        y: parent.height* (1-blockWidth) / 2
        width: parent.width * blockWidth;
        height: parent.height * blockWidth;
        radius: width * edgeRadius;
    }

    Rectangle{
        id: up;
        color: "peru";
        x: parent.width * (1-blockWidth) / 2;
        y: 0;
        width: parent.width * blockWidth;
        height: parent.height * ((1-blockWidth) / 2 + edgeRadius);
        visible: false;
    }

    Rectangle{
        id: left;
        color: "peru";
        x: 0;
        y: parent.height * (1-blockWidth) / 2;
        width: parent.width * ((1-blockWidth) / 2 + edgeRadius);
        height: parent.height * blockWidth;
        visible: false;
    }

    Rectangle{
        id: down;
        color: "peru";
        x: parent.width * (1-blockWidth) / 2;
        y: parent.height * ( 1 - ( (1-blockWidth) / 2 + edgeRadius) );
        width: parent.width * blockWidth;
        height: parent.height * ((1-blockWidth) / 2 + edgeRadius);
        visible: false;
    }

    Rectangle{
        id: right;
        color: "peru";
        x: parent.width * ( 1 - ( (1-blockWidth) / 2 + edgeRadius) );
        y: parent.height * (1-blockWidth) / 2;
        width: parent.width * ((1-blockWidth) / 2 + edgeRadius);
        height: parent.height * blockWidth;
        visible: false;
    }

    Component.onCompleted: {
        if( show % 2 )
            left.visible = true;
        if( Math.floor(show / 2) % 2 )
            up.visible = true;
        if( Math.floor(show / 4) % 2 )
            right.visible = true;
        if( Math.floor(show / 8) % 2 )
            down.visible = true;
    }
}
