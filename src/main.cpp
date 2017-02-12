#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include <QObject>
#include <QDebug>
#include "channel.h"
#include "map.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Map mymap(15,15);
    Agent agent(&mymap);
    Channel channel(&mymap, &agent);

    //QQuickView view(QUrl(QStringLiteral("qrc:///qml/Agent.qml")));
    //view.show();
    //QObject *item = view.rootObject();
    //QObject::connect(item, SIGNAL(move(int)), &c, SLOT(agentMove(int)));

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("channel", &channel);
    engine.load(QUrl(QStringLiteral("qrc:///qml/AppWindow.qml")));

    QObject *qagent = engine.rootObjects().first()->findChild<QObject*>("agent");
    QObject::connect(qagent, SIGNAL(move(int)), &channel, SLOT(agentMove(int)));
    QObject::connect(&channel, SIGNAL(onAgentPosChanged(int,int)), qagent, SIGNAL(renewPos(int,int)));

    QObject *littleMap = engine.rootObjects().first()->findChild<QObject*>("littleMap");
    QObject::connect(&channel, SIGNAL(buildWalls(int,int)), littleMap, SIGNAL(buildWalls(int,int)));
    channel.loadMap();

    return app.exec();
}


