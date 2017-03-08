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
}

RightAgent::~RightAgent() {
    //delete car;
}

Position RightAgent::getNextPosition( const Map *map ) {

    Position nextPos( agentPos );
    vector<Position> legalMoves = getLegalMoves( map, agentPos );

    for( int i = 0; i < 4; ++i ) {
        nextPos = agentPos.getAdjacent( direction, 1 );
        if( std::find( legalMoves.begin(), legalMoves.end(), nextPos ) != legalMoves.end() ) {
            break;
        }
        else {
            direction = Direction( (direction + 1) % 4 );
        }
    }

    return nextPos;
}

