import QtQuick 2.0
import QtQuick.Controls 1.1

ApplicationWindow {
    id: appWindow;
    objectName: "appWindow";
    visible: true;

    Map {
        id: map;
        objectName: "map";
        w: channel.mw;
        h: channel.mh;
        blockSize: 720/channel.mw>720/channel.mh ? 720/channel.mh : 720/channel.mw;
        x: 0;
        y: 0;

        signal kbAgentMove(int d);

        Connections{
            target: channel;

            onQtDrawObject: {
                if(typeof map.objects[id] == "undefined"){
                    if(type < 4 && type > 0){
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
                                "size": map.blockSize,
                                "x": y * map.blockSize,
                                "y": x * map.blockSize,
                                "int_id": id
                            });
                            map.objects[id] = object;
                        }
                    }
                }else{
                    map.objects[id].x = y * map.blockSize;
                    map.objects[id].y = x * map.blockSize;
                }
            }
            onRegisterKbAgent: {
                var component = Qt.createComponent("Car.qml");
                var object = component.createObject(map, {
                    "size": map.blockSize,
                    "x": y * map.blockSize,
                    "y": x * map.blockSize,
                    "int_id": id,
                    "c_color": "lime"
                });
                map.objects[id] = object;
            }
        }

        focus: true;
        Keys.onPressed: {
            if (event.key == Qt.Key_Down) {
                kbAgentMove(1);
            }else if (event.key == Qt.Key_Right) {
                kbAgentMove(2);
            }else if (event.key == Qt.Key_Up) {
                kbAgentMove(3);
            }else if (event.key == Qt.Key_Left) {
                kbAgentMove(4);
            }
            event.accepted = true;
        }
    }

    Timer{
        id: gameTimer;
        objectName: "timer";
        signal run();

        interval: 200; running: true; repeat: true;
        onTriggered: run();
    }
}
