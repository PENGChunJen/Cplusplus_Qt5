#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>

#include "position.h"
#include "map.h"
#include "dfsAgent.h"

using std::cout; using std::endl;
using std::vector; using std::string; using std::map;

DFSAgent::DFSAgent(size_t _id, const Position& _pos, const std::string &_name, const std::string &_plate)
        :Agent(_id, _pos, _name, _plate) {
        route.clear();
}

DFSAgent::~DFSAgent() {
    //delete car;
}

Position DFSAgent::getNextPosition( const Map *map ) {
    if( route.empty() ) {
        findRoute( map );
    }

    Position nextPos = route.back();
    if( map->isLegal(nextPos) ) {
        route.pop_back();
    }
    else {
        route.clear();
        nextPos = agentPos;
    }
    return nextPos;
}


void DFSAgent::findRoute( const Map *map ) {
    route.clear();

    vector<Position> stack; 
    std::map<Position, Position> trace;
    Position target = getNearestPark( map );
    Position nextPos = agentPos;

    stack.push_back( agentPos );
    trace[agentPos] = agentPos;
    
    while( !stack.empty() ) {

        Position pos = stack.back();
        stack.pop_back();
        
        vector<Position> legalMoves = getLegalMoves( map, pos );
        std::random_shuffle( legalMoves.begin(), legalMoves.end() );

        for( Position& legalMove : legalMoves ) {
            if( legalMove == pos ){
                continue;
            }
            else if( trace.find(legalMove) == trace.end() ) {
                trace[legalMove] = pos;
                stack.push_back(legalMove);

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
