#ifndef GAME_H
#define GAME_H

#include <vector>
#include "agent.h"
#include "kbAgent.h"
#include "map.h"

class Game{

public:
    Game(int w, int h);
    Game( const std::string& filename );
    ~Game();

    Map* getMap() const { return mapPtr; }
    KeyboardAgent* getKbAgent() const { return kbAgent; }

    bool moveAgent( Agent* agent );
    bool shouldTerminate();

    void run();
    void printStatus() const;

private:
    Map* mapPtr;
    std::vector<Agent*> agents;
    bool hasEnd;
    KeyboardAgent* kbAgent;
};

#endif // GAME_H

