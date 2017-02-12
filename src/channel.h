#ifndef CHANNEL_H
#define CHANNEL_H

#include <QObject>
#include "map.h"
#include "agent.h"

class Channel : public QObject{
    Q_OBJECT
    Q_PROPERTY(int mw READ mw)
    Q_PROPERTY(int mh READ mh)
    Q_PROPERTY(int ax READ ax)
    Q_PROPERTY(int ay READ ay)
public:
    Channel(Map *m, Agent *a){
        map = m;
        agent = a;
    }
    int mw() const { return map->w(); }
    int mh() const { return map->h(); }
    int ax() const { return agent->x(); }
    int ay() const { return agent->y(); }

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
        agent->move((Direction)d);
        emit onAgentPosChanged(ax(), ay());
    }
private:
    Map *map;
    Agent *agent;
};

#endif // CHANNEL_H
