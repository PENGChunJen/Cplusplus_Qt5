#ifndef CHANNEL_H
#define CHANNEL_H

#include <QObject>
#include "map.h"

class Channel : public QObject{
    Q_OBJECT
    Q_PROPERTY(int w READ w)
    Q_PROPERTY(int h READ h)
    Q_PROPERTY(int ax READ ax)
    Q_PROPERTY(int ay READ ay)
public:
    Channel(Map *m){
        this->map = m;
    }
    int w() const { return map->w(); }
    int h() const { return map->h(); }
    int ax() const { return map->ax(); }
    int ay() const { return map->ay(); }

    void loadMap(){
        for(int i=0; i<map->walls.size(); i++){
            emit buildWalls(map->walls[i].x, map->walls[i].y);
        }
    }
signals:
    void onAgentPosChanged(int x, int y);
    void buildWalls(int x, int y);
public slots:
    void agentMove(const int d) {
        map->agentMove((Direction)d);
        emit onAgentPosChanged(map->ax(), map->ay());
    }
private:
    Map *map;
};

#endif // CHANNEL_H
