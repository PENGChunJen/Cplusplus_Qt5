#ifndef RIGHTAGENT_H 
#define RIGHTAGENT_H

#include "position.h"
#include "map.h"
#include "agent.h"

class RightAgent : public Agent {

public:
    RightAgent(size_t _id, const Position& _pos, const std::string &_name, const std::string &_plate);
    ~RightAgent();

    Position getNextPosition( const Map* map );
private:
    Direction direction;
    Position lastPosition;
};

#endif // RIGHTAGENT_H
