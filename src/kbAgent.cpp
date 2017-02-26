#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

#include "kbAgent.h"

using std::vector; using std::string; using std::cout; using std::endl; using std::find;

KeyboardAgent::KeyboardAgent(size_t _id, const Position& _pos, const std::string &_name, const std::string &_plate)
        :Agent(_id, _pos, _name, _plate) {
}

KeyboardAgent::~KeyboardAgent(){
    //delete car;
}

Position KeyboardAgent::getNextPosition( const Map *map ){
    vector<Position> legalMoves = getLegalMoves( map );

    Position nextPosition;
    if(direction == 1){
        nextPosition = Position(agentPos.x+1, agentPos.y);
    }else if(direction == 2){
        nextPosition = Position(agentPos.x, agentPos.y+1);
    }else if(direction == 3){
        nextPosition = Position(agentPos.x-1, agentPos.y);
    }else if(direction == 4){
        nextPosition = Position(agentPos.x, agentPos.y-1);
    }else{
        nextPosition = Position(agentPos.x, agentPos.y);
    }

    direction = 0;

    bool PRINT = false;
    if( PRINT ) {
        cout << "(" << nextPosition.x << ", " << nextPosition.y << ")" << endl;
    }

    if( find(legalMoves.begin(), legalMoves.end(), nextPosition) != legalMoves.end() ){
        return nextPosition;
    }

    return agentPos;
}
