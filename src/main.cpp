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

    Map mymap;
    Channel c(&mymap);

    //QQuickView view(QUrl(QStringLiteral("qrc:///qml/Agent.qml")));
    //view.show();
    //QObject *item = view.rootObject();
    //QObject::connect(item, SIGNAL(move(int)), &c, SLOT(agentMove(int)));

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("map", &c);
    engine.load(QUrl(QStringLiteral("qrc:///qml/AppWindow.qml")));

    QObject *agent = engine.rootObjects().first()->findChild<QObject*>("agent");
    QObject::connect(agent, SIGNAL(move(int)), &c, SLOT(agentMove(int)));
    QObject::connect(&c, SIGNAL(onAxChanged(int)), agent, SIGNAL(onAxChanged(int)));
    QObject::connect(&c, SIGNAL(onAyChanged(int)), agent, SIGNAL(onAyChanged(int)));

    return app.exec();
}


