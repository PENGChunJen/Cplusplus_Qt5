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

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    srand( time(NULL) );
    Game game(9,9);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("channel", game.getMapChannel());
    engine.load(QUrl(QStringLiteral("qrc:///qml/AppWindow.qml")));

    while( !game.shouldTerminate() ) {
        game.run();
        //cin.get();
        //cin.sync();
    }

    return app.exec();
}


