#ifndef GAME_H
#define GAME_H

#include <vector>
#include "agent.h"
#include "kbAgent.h"
#include "map.h"

class Game{

public:
    Game();
    ~Game();

    Map* getMap() const { return mapPtr; }
    KeyboardAgent* getKbAgent() const { return kbAgent; }

    bool moveAgent( Agent* agent );
    bool shouldTerminate();

    void addAgents();
    void addParks();
    void run();
    void printStatus() const;

private:
    Map* mapPtr;
    std::vector<Agent*> agents;
    bool hasEnd;
    KeyboardAgent* kbAgent;
};

#endif // GAME_H

