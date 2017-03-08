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
}

DFSAgent::~DFSAgent() {
    //delete car;
}

Position DFSAgent::getNextPosition( const Map *map ) {

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
        cout << pos << ":";
        for( Position& legalMove : legalMoves ) {
            cout << legalMove << ",";
            if( legalMove == target ) {
                nextPos = pos;
                stack.clear();
                break;
            }
            else if( legalMove == pos ){
                continue;
            }
            else if( trace.find(legalMove) == trace.end() ) {
                trace[legalMove] = pos;
                stack.push_back(legalMove);
            }
        }
        cout << endl;
    }

    while( trace.find(nextPos) != trace.end() && trace[nextPos] != agentPos ) {
        cout << trace[nextPos] << "<-";
        nextPos = trace[nextPos];
    }
    cout << endl;
    
    printMoves(stack, nextPos);
    return nextPos;
}
