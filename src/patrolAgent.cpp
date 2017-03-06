#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "map.h"
#include "patrolAgent.h"

using std::vector; using std::string; using std::cout; using std::endl;

PatrolAgent::PatrolAgent(size_t _id, const Position& _pos, const std::string &_name, const std::string &_plate)
        :Agent(_id, _pos, _name, _plate) {
    direction = 0;
}

PatrolAgent::~PatrolAgent() {
    //delete car;
}

Position PatrolAgent::getNextPosition( const Map *map ) {

    vector<Position> legalMoves = getLegalMoves( map, agentPos );

    for( int i = 0; i < 4; ++i ) {
        Position nextPos = map->getAdjacent( agentPos, direction, 1 ); 
        if( std::find( legalMoves.begin(), legalMoves.end(), nextPos ) != legalMoves.end() ) {
           return nextPos;
        }
        else {
            direction = (direction + 1) % 4;
        }
    }
    return agentPos;

    bool PRINT = false;
    if( PRINT ) {
        cout << "legalMove: ";
        for( Position& p : legalMoves ) {
            cout << "(" << p.x << ", " << p.y << "),";
        }
        cout << "\b " << endl
             <<"choseMove: (" << legalMoves.front().x << ", " << legalMoves.front().y << ")" << endl;
    }

}

