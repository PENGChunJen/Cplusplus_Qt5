import QtQuick 2.0
import QtQuick.Controls 1.1

ApplicationWindow {
    id: appWindow;
    objectName: "appWindow";
    visible: true;

    Map {
        id: map;
        w: channel.mw;
        h: channel.mh;
        blockSize: 720/channel.mw>720/channel.mh ? 720/channel.mh : 720/channel.mw;
        x: 0;
        y: 0;

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
                                "x": x * map.blockSize,
                                "y": y * map.blockSize,
                                "int_id": id
                            });
                            map.objects[id] = object;
                        }
                    }
                }else{
                    map.objects[id].x = x * map.blockSize;
                    map.objects[id].y = y * map.blockSize;
                }
            }
        }
    }

    Timer{
        objectName: "timer";
        signal run();

        interval: 1000; running: true; repeat: true;
        onTriggered: run();
    }
}
