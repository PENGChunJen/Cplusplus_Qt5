import QtQuick 2.0

Item {
    id: root;
    property int x_max: 3;
    property int y_max: 3;
    property int blockSize: 100;
    property var objects: [];
    width: x_max * blockSize;
    height: y_max * blockSize;

    Rectangle {
        anchors.fill: parent;
        color: "black";
    }

    function drawPark(id, type, x, y, free){
        if(typeof objects[id] == "undefined"){
            var component = Qt.createComponent("Park.qml");
            if (component.status === Component.Ready){
                var object = component.createObject(root, {
                    "size": blockSize,
                    "x": y * blockSize,
                    "y": x * blockSize,
                    "int_id": id
                });
                objects[id] = object;
            }
        }else{
            objects[id].x = y * blockSize;
            objects[id].y = x * blockSize;
        }
        objects[id].setFreeNumber(free);
    }

    function drawWall(id, show, x, y){
        if(typeof objects[id] == "undefined"){
            var component = Qt.createComponent("Wall.qml");
            if (component.status === Component.Ready){
                var object = component.createObject(root, {
                    "size": blockSize,
                    "x": y * blockSize,
                    "y": x * blockSize,
                    "int_id": id,
                    "show": show
                });
                objects[id] = object;
            }
        }else{
            objects[id].x = y * blockSize;
            objects[id].y = x * blockSize;
        }
    }

    function drawCar(id, name, x, y, isKA){
        if(typeof objects[id] == "undefined"){
            var component = Qt.createComponent("Car.qml");
            if (component.status === Component.Ready){
                var object = component.createObject(root, {
                    "size": root.blockSize,
                    "x": y * root.blockSize,
                    "y": x * root.blockSize,
                    "int_id": id,
                    "owner": name
                });
                if(isKA) object.setToKeyAgent();
                root.objects[id] = object;
            }
        }else{
            objects[id].x = y * blockSize;
            objects[id].y = x * blockSize;
        }
    }

    function genStartPanel(startTimer){
        var component = Qt.createComponent("GameStartPanel.qml");
        if (component.status === Component.Ready){
            var object = component.createObject(root, {
                "anchors.horizontalCenter": root.horizontalCenter,
                "anchors.verticalCenter": root.verticalCenter,
                "startTimer": startTimer
            });
        }
    }

    function genTerminatePanel(kbRank, kbScore){
        var component = Qt.createComponent("GameOverPanel.qml");
        if (component.status === Component.Ready){
            var object = component.createObject(root, {
                "anchors.horizontalCenter": root.horizontalCenter,
                "anchors.verticalCenter": root.verticalCenter,
                "kbRank": kbRank,
                "kbScore": kbScore
            });
        }
    }

    function reset(){
        console.log("Map reset!");
        objects = [];
    }

    function restart(){

    }
}

