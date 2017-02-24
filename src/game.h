#ifndef GAME_H
#define GAME_H

#include <vector>
#include "channel.h"
#include "agent.h"
#include "map.h"

class Game{

public:
    Game(int w, int h);
    Game( const std::string& filename );
    ~Game();

    bool moveAgent( Agent& agent ); 
    void printMap() const;
    bool shouldTerminate();

    void run();
    void printStatus() const;

    MapChannel* getMapChannel() const { return map->getChannel(); }


private:
    Map* mapPtr;
    std::vector<Agent> agents;
    bool hasEnd;
};

#endif // GAME_H

