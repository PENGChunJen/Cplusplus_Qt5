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
    delete car;
}

Position RandomAgent::getNextPosition( Map *map ) {
    vector<Position> legalMoves = getLegalMoves( map );
    int r = rand() % legalMoves.size();
    return legalMoves.at(r);
}

