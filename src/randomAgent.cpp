#include <cstdlib>
#include <iostream>
#include <vector>

#include "map.h"
#include "randomAgent.h"

using std::vector; using std::string; using std::cout; using std::endl;

RandomAgent::RandomAgent(size_t _id, const Position& _pos, const std::string &_name, const std::string &_plate)
        :Agent(_id, _pos, _name, _plate) {
}

RandomAgent::~RandomAgent() {
    //delete car;
}

Position RandomAgent::getNextPosition( const Map *map ) {
    vector<Position> legalMoves = getLegalMoves( map );
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

