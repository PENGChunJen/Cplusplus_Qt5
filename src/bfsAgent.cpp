#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <queue>

#include "position.h"
#include "map.h"
#include "bfsAgent.h"

using std::cout; using std::endl;
using std::vector; using std::string; using std::map; using std::queue;

BFSAgent::BFSAgent(size_t _id, const Position& _pos, const std::string &_name, const std::string &_plate)
        :Agent(_id, _pos, _name, _plate) {
        route.clear();
}

BFSAgent::~BFSAgent() {
    //delete car;
}

Position BFSAgent::getNextPosition( const Map *map ) {
    if( route.empty() ) {
        findRoute( map );
    }
    Position nextPos = route.back();
    route.pop_back();
    return nextPos;
}


void BFSAgent::findRoute( const Map *map ) {

    route.clear();

    queue<Position> queue;
    std::map<Position, Position> trace;
    Position target = getNearestPark( map );
    Position nextPos = agentPos;

    queue.push( agentPos );
    trace[agentPos] = agentPos;
    
    while( !queue.empty() ) {

        Position pos = queue.front();
        queue.pop();
        
        vector<Position> legalMoves = getLegalMoves( map, pos );
        std::random_shuffle( legalMoves.begin(), legalMoves.end() );

        for( Position& legalMove : legalMoves ) {
            if( legalMove == pos ){
                continue;
            }
            else if( trace.find(legalMove) == trace.end() ) {
                trace[legalMove] = pos;
                queue.push(legalMove);

                if( legalMove == target ) {
                    nextPos = legalMove;
                    break;
                }
            }
        }
    }

    while( trace.find(nextPos) != trace.end() && trace[nextPos] != agentPos ) {
        route.push_back(nextPos);
        nextPos = trace[nextPos];
    }
    route.push_back(nextPos);
}
