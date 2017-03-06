#ifndef DFSAGENT_H 
#define DFSAGENT_H

#include "map.h"
#include "agent.h"

class DFSAgent : public Agent {

public:
    DFSAgent(size_t _id, const Position& _pos, const std::string &_name, const std::string &_plate);
    ~DFSAgent();

    Position getNextPosition( const Map* map );
};

#endif // DFSAGENT_H
