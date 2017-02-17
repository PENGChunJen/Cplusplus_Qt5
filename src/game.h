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

    bool moveAgent( Agent& agent ); 
    void printMap() const { map->printMap(); }
    bool shouldTerminate();

    void run();
    void printStatus() const;


private:
    Map* map;
    std::vector<Agent> agents;
    bool hasEnd;
};

#endif // GAME_H

