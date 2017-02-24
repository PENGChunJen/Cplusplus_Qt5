import QtQuick 2.0
import QtQuick.Controls 1.1

ApplicationWindow {
    id: appWindow;
    objectName: "appWindow";
    visible: true;

    property int blockSize: 720/channel.mw>720/channel.mh ? 720/channel.mh : 720/channel.mw;

    Rectangle {
        id: map;
        //w: channel.mw;
        //h: channel.mh;
        //blockSize: appWindow.blockSize;
        x: 0;
        y: 0;

        property var objects: [];
        width: appWindow.blockSize * channel.mw;
        height: appWindow.blockSize * channel.mw;

        anchors.fill: parent;
        color: "black";

        Connections{
            target: channel;

            onQtDrawObject: {
                if(typeof objects[id] == "undefined"){
                    var component;
                    if(type==1){
                        component = Qt.createComponent("Wall.qml");
                    }else if(type==2){
                        component = Qt.createComponent("Park.qml");
                    }else if(type==3){
                        component = Qt.createComponent("Car.qml");
                    }
                    if (component.status == Component.Ready){
                        var object = component.createObject(map, {
                            "size": blockSize,
                            "x": x * blockSize,
                            "y": y * blockSize,
                            "int_id": id
                        });
                        map.objects[id] = object;
                    }
                }else{
                    map.objects[id].x = x * blockSize;
                    map.objects[id].y = y * blockSize;
                }
            }
        }
    }
}
