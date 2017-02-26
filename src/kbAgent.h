#ifndef KBAGENT_H
#define KBAGENT_H

#include "map.h"
#include "agent.h"

class KeyboardAgent : public Agent {

public:
    KeyboardAgent(size_t _id, const Position& _pos, const std::string &_name, const std::string &_plate);
    ~KeyboardAgent();

    void setDirection( const unsigned int d ) { direction = d<=4 ? d : 0; }
    Position getNextPosition( const Map* map );
private:
    unsigned int direction;
};

#endif // RANDOMAGENT_H
