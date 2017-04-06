#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include <QObject>
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "game.h"
#include "channel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    srand( time(NULL) );
    Game game;
    GameChannel gc(&game);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("channel", &gc);
    engine.load(QUrl(QStringLiteral("qrc:///src/qml/AppWindow.qml")));

    QObject *qtimer = engine.rootObjects().first()->findChild<QObject*>("timer");
    QObject::connect(qtimer, SIGNAL(run()), &gc, SLOT(onGameRun()));

    QObject *qmap = engine.rootObjects().first()->findChild<QObject*>("map");
    QObject::connect(qmap, SIGNAL(kbAgentMove(int)), &gc, SLOT(onKbAgentMove(int)));

    gc.drawKbCar();
    gc.printGameMap();

    return app.exec();
}


