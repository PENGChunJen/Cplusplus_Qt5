#ifndef GAME_H
#define GAME_H

#include <vector>
#include "agent.h"
#include "map.h"

class Game{

public:
    Game(int w, int h);
    Game( const std::string& filename );
    ~Game();

    Map* getMap() const { return mapPtr; }

    bool moveAgent( Agent& agent );
    bool shouldTerminate();

    void run();
    void printStatus() const;

    //MapChannel* getChannel() const { return mapPtr->getChannel(); }


private:
    Map* mapPtr;
    std::vector<Agent> agents;
    bool hasEnd;
};

#endif // GAME_H

