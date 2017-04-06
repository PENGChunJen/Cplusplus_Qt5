import QtQuick 2.0

Item {
    id: root;
    property int size: 100;
    property int int_id: 0;
    property int show: 15;
    property real blockWidth: 0.6;
    property real edgeRadius: 0.2;
    property string w_color: "peru";
    width: size;
    height: size;

    Rectangle {
        id: main;
        color: w_color;
        x: parent.width * (1-blockWidth) / 2
        y: parent.height* (1-blockWidth) / 2
        width: parent.width * blockWidth;
        height: parent.height * blockWidth;
        radius: width * edgeRadius;
    }

    Rectangle{
        id: up;
        color: w_color;
        x: parent.width * (1-blockWidth) / 2;
        y: 0;
        width: parent.width * blockWidth;
        height: parent.height * ((1-blockWidth) / 2 + edgeRadius);
        visible: false;
    }

    Rectangle{
        id: left;
        color: w_color;
        x: 0;
        y: parent.height * (1-blockWidth) / 2;
        width: parent.width * ((1-blockWidth) / 2 + edgeRadius);
        height: parent.height * blockWidth;
        visible: false;
    }

    Rectangle{
        id: down;
        color: w_color;
        x: parent.width * (1-blockWidth) / 2;
        y: parent.height * ( 1 - ( (1-blockWidth) / 2 + edgeRadius) );
        width: parent.width * blockWidth;
        height: parent.height * ((1-blockWidth) / 2 + edgeRadius);
        visible: false;
    }

    Rectangle{
        id: right;
        color: w_color;
        x: parent.width * ( 1 - ( (1-blockWidth) / 2 + edgeRadius) );
        y: parent.height * (1-blockWidth) / 2;
        width: parent.width * ((1-blockWidth) / 2 + edgeRadius);
        height: parent.height * blockWidth;
        visible: false;
    }

    Rectangle{
        id: up_left;
        color: w_color;
        x: 0;
        y: 0;
        width: parent.width * (1-blockWidth) / 2;
        height: parent.height * (1-blockWidth) / 2;
        visible: false;
    }

    Rectangle{
        id: down_left;
        color: w_color;
        x: 0;
        y: parent.height * (1+blockWidth) / 2;
        width: parent.width * (1-blockWidth) / 2;
        height: parent.height * (1-blockWidth) / 2;
        visible: false;
    }

    Rectangle{
        id: up_right;
        color: w_color;
        x: parent.width * (1+blockWidth) / 2;
        y: 0;
        width: parent.width * (1-blockWidth) / 2;
        height: parent.height * (1-blockWidth) / 2;
        visible: false;
    }

    Rectangle{
        id: down_right;
        color: w_color;
        x: parent.width * (1+blockWidth) / 2;
        y: parent.height * (1+blockWidth) / 2;
        width: parent.width * (1-blockWidth) / 2;
        height: parent.height * (1-blockWidth) / 2;
        visible: false;
    }

    Component.onCompleted: {
        if( show & 1 )
            left.visible = true;
        if( show & 2 )
            up.visible = true;
        if( show & 4 )
            right.visible = true;
        if( show & 8 )
            down.visible = true;
        if( show & 16 )
            up_left.visible = true;
        /*if( show & 32 )
            up_right.visible = true;
        if( show & 64 )
            down_right.visible = true;
        if( show & 128 )
            down_left.visible = true;*/
    }
}
