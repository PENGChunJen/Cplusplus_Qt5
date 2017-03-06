#ifndef GAME_H
#define GAME_H

#include <vector>
#include "agent.h"
#include "park.h"
#include "kbAgent.h"
#include "map.h"

class Game{

public:
    Game();
    ~Game();

    Map* getMap() const { return mapPtr; }
    KeyboardAgent* getKbAgent() const { return kbAgent; }

    void run();
    bool shouldTerminate();

    void addAgents();
    bool moveAgent( Agent* agent );

    void addParks(const std::string& config = "default");
    Position tw97ToPosition( const double originX, const double originY, 
                             const double tw97x, const double tw97y, const double scale );
    Position generationPosition();

    void printStatus() const;

private:
    Map* mapPtr;
    std::vector<Agent*> agents;
    std::vector<Park*> parks;
    
    /* Why isolate here? */
    KeyboardAgent* kbAgent;
};

#endif // GAME_H

