#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "map.h"
#include "rightAgent.h"

using std::vector; using std::string; using std::cout; using std::endl;

RightAgent::RightAgent(size_t _id, const Position& _pos, const std::string &_name, const std::string &_plate)
        :Agent(_id, _pos, _name, _plate) {
    direction = North;
    lastPosition = _pos;
}

RightAgent::~RightAgent() {
    //delete car;
}

Position RightAgent::getNextPosition( const Map *map ) {

    if(agentPos == lastPosition) {
        direction = Direction( rand() % 4 );
    }
    lastPosition = agentPos;

    Position nextPos( agentPos );
    vector<Position> legalMoves = getLegalMoves( map, agentPos );

    for( int i = 0; i < 4; ++i ) {
        nextPos = agentPos.getAdjacent( direction, 1 );
        if( std::find( legalMoves.begin(), legalMoves.end(), nextPos ) != legalMoves.end() ) {
            break;
        }
        else {
            //direction = Direction( (direction + 1) % 4 );
            direction = Direction( rand() % 4 );
        }
    }

    return nextPos;
}

