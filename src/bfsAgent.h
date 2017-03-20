#ifndef BFSAGENT_H 
#define BFSAGENT_H

#include "map.h"
#include "agent.h"

class BFSAgent : public Agent {

public:
    BFSAgent(size_t _id, const Position& _pos, const std::string &_name, const std::string &_plate);
    ~BFSAgent();

    Position getNextPosition( const Map *map );
    void findRoute( const Map *map );

private:
    std::vector<Position> route;
};

#endif // BFSAGENT_H
