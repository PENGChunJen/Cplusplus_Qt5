#ifndef RANDOMAGENT_H 
#define RANDOMAGENT_H

#include "map.h"
#include "agent.h"

class RandomAgent : public Agent {

public:
    RandomAgent(size_t _id, const Position& _pos, const std::string &_name, const std::string &_plate);
    ~RandomAgent();

    Position getNextPosition( Map* map );
};

#endif // RANDOMAGENT_H
