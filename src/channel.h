#ifndef CHANNEL_H
#define CHANNEL_H

#include <QObject>
#include "game.h"

class GameChannel : public QObject{
    Q_OBJECT
    Q_PROPERTY(int mw READ mw)
    Q_PROPERTY(int mh READ mh)
public:
    GameChannel (Game* g){
        game = g;
    }
    int mw() const { return game->getMap()->getWidth(); }
    int mh() const { return game->getMap()->getHeight(); }
signals:
    void qtDrawObject(int id, int type, int x, int y);
public slots:
    void onGameRun(){
        run();
        printGameMap();
    }
private:
    void run();
    void printGameMap();
    void drawObject(int id, int type, int x, int y){
        emit qtDrawObject(id, type, x, y);
    }

    Game* game;
};

class MapChannel : public QObject{
    Q_OBJECT
    Q_PROPERTY(int mw READ mw)
    Q_PROPERTY(int mh READ mh)
public:
    MapChannel(int _w, int _h){
        w = _w;
        h = _h;
    }
    int mw() const { return w; }
    int mh() const { return h; }
    void drawObject(int id, int type, int x, int y){
        emit qtDrawObject(id, type, x, y);
    }
    /*void buildObject(int id, int type, int x, int y){
        emit qtBuildObject(id, type, x, y);
    }*/

signals:
    void qtDrawObject(int id, int type, int x, int y);
    //void qtBuildObject(int id, int type, int x, int y);
private:
    int w, h;
};

#endif // CHANNEL_H
