#ifndef CHANNEL_H
#define CHANNEL_H

#include <QObject>

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

class Game;

class GameChannel : public QObject{
    Q_OBJECT
public:
    GameChannel (Game* g){
        game = g;
    }

public slots:
    void onGameRun(){
        run();
    }
private:
    void run();
    Game* game;
};

#endif // CHANNEL_H
