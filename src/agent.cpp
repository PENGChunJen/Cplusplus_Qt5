//#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "car.h"
#include "map.h"
#include "agent.h"

using std::cout; using std::endl; using std::vector; 

Agent::Agent(size_t _id, const Position& _pos, const std::string &_name, const std::string &_plate) {
    id = _id; 
    agentPos = _pos;
    name = _name;
    car = new Car(_name, _plate);
}

Agent::~Agent() {
    //delete car;
}

vector<Position> Agent::getLegalMoves( const Map *map, const Position& pos ) {

    // Difference between constructor, reserve(), resize() 
    vector<Position> possibleMoves, legalMoves;
    possibleMoves.reserve(8);
    legalMoves.reserve(8);

    possibleMoves.push_back( Position(pos.x-1, pos.y) );
    possibleMoves.push_back( Position(pos.x, pos.y-1) );
    possibleMoves.push_back( Position(pos.x+1, pos.y) );
    possibleMoves.push_back( Position(pos.x, pos.y+1) );
    possibleMoves.push_back( Position(pos.x, pos.y) );

    for( Position& possiblePos : possibleMoves ) {
        if( map->isLegal(possiblePos) ) {
            legalMoves.push_back( possiblePos );
        }
    }

    return legalMoves;
}

void Agent::printStatus() const {
    cout << "{" << endl
         << "\t name: " << name << endl
         << "\t id: " << id << endl
         << "\t position: (" << agentPos.x << ", " << agentPos.y << ")" << endl
         << "}" << endl;
}

Position Agent::getNextPosition( const Map *map ) {

    vector<Position> legalMoves = getLegalMoves( map, agentPos );

    int r = rand() % legalMoves.size();
    return legalMoves.at(r);

}

