#include <cstdlib>
#include <iostream>
#include <stack>
#include <vector>

#include "map.h"
#include "dfsAgent.h"

using std::cout; using std::endl;
using std::vector; using std::string; using std::stack;

DFSAgent::DFSAgent(size_t _id, const Position& _pos, const std::string &_name, const std::string &_plate)
        :Agent(_id, _pos, _name, _plate) {
}

DFSAgent::~DFSAgent() {
    //delete car;
}

Position DFSAgent::getNextPosition( const Map *map ) {

    Position target = getNearestPark( map );
    stack<Position> stack; 

    s.push( agentPos );
    
    while( 
    vector<Position> legalMoves = getLegalMoves( map, agentPos );

    int r = rand() % legalMoves.size();

    bool PRINT = false;
    if( PRINT ) {
        cout << "legalMove: ";
        for( Position& p : legalMoves ) {
            cout << "(" << p.x << ", " << p.y << "),";
        }
        cout << "\b " << endl
             <<"choseMove: (" << legalMoves.at(r).x << ", " << legalMoves.at(r).y << ")" << endl;
    }

    return legalMoves.at(r);
}

