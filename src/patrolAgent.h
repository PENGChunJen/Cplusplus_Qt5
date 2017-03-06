#ifndef PATROLAGENT_H 
#define PATROLAGENT_H

#include "map.h"
#include "agent.h"

class PatrolAgent : public Agent {

public:
    PatrolAgent(size_t _id, const Position& _pos, const std::string &_name, const std::string &_plate);
    ~PatrolAgent();

    Position getNextPosition( const Map* map );
private:
    int direction;
};

#endif // PATROLAGENT_H
