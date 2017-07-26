import QtQuick 2.0

Item {
    id: root;
    property var objects: [];
    width: 320;

    Rectangle{
        id: bg;
        anchors.fill: parent;
        color: "black";
    }

    Rectangle{
        width: parent.width;
        height: 80;
        color: "transparent";
        Text{
            id: t_text;
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.verticalCenter: parent.verticalCenter;
            text: "Scordboard";
            font.family: "Arial Black";
            font.pixelSize: 40;
            color: "cornsilk";
        }
    }

    function renew(id, rank, name, score, isKA){
        if(typeof objects[id] == "undefined"){
            var component = Qt.createComponent("ScoreBoardItem.qml");
            if (component.status === Component.Ready){
                var object = component.createObject(root, {
                    "x": 0,
                    "y": 80 * rank,
                    "width": root.width,
                    "name": name,
                    "rank": rank,
                    "score": score,
                    "isKA": isKA
                });
                root.objects[id] = object;
            }
        }else{
            objects[id].score = score;
            objects[id].rank = rank;
            objects[id].y = 80 * rank;
        }
    }
}
