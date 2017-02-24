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
    Game game(9,9);
    GameChannel gc(&game);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("channel", game.getMapChannel());
    engine.load(QUrl(QStringLiteral("qrc:///qml/AppWindow.qml")));

    QObject *qtimer = engine.rootObjects().first()->findChild<QObject*>("timer");
    QObject::connect(qtimer, SIGNAL(run()), &gc, SLOT(onGameRun()));

    /*while( !game.shouldTerminate() ) {
        game.run();
        //cin.get();
        //cin.sync();
    }*/

    return app.exec();
}


