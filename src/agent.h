#ifndef AGENT_H
#define AGENT_H

#include "map.h"

class Agent{
public:
    Agent(Map *m, int ax=0, int ay=0){
        putOntoMap(m, ax, ay);
    }
    void putOntoMap(Map* m, int ax, int ay){
        map = m;
        if(map->isGridEmpty(gridPos{ax,ay})){
            pos.x = ax; pos.y = ay;
        }else{
            pos = map->findAnEmptyPlace();
        }
    }
    int x() const{
        return pos.x;
    }
    int y() const{
        return pos.y;
    }
    void move(Direction d){
        map->checkNextStep(pos, d);
    }

private:
    gridPos pos;
    Map *map;
};

#endif // AGENT_H
