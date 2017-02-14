//#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "car.h"
#include "map.h"
#include "agent.h"

using std::cout; using std::endl; using std::vector; 

Agent::Agent(size_t _id, const Position& _pos, const std::string &_name, const std::string &_plate) {
    id = _id; pos = _pos;
    this->name = _name;
    car = new Car(_name, _plate);
}

Agent::~Agent() {
    delete car;
}

vector<Position> Agent::getLegalMoves( Map* map ) {

    // Difference between constructor, reserve(), resize() 
    vector<Position> allMoves(5);
    vector<Position> legalMoves;
    legalMoves.reserve(5);

    // Difference between [] and .at() 
    allMoves.at(0) = Position( pos.x-1, pos.y );
    allMoves.at(1) = Position( pos.x+1, pos.y );
    allMoves.at(2) = Position( pos.x, pos.y-1 );
    allMoves.at(3) = Position( pos.x, pos.y+1 );
    allMoves.at(4) = pos;
    
    for( auto it = allMoves.begin(); it != allMoves.end(); ++it ) {

        Position nextPos = *it;
        //nextPos.print();
        //map->printMap();
        if( map->isLegal(nextPos) ) {
            //cout << "legalMoves: " << nextPos.x << ", " << nextPos.y << endl;
            legalMoves.push_back( nextPos );
        }
    }
    return legalMoves;
}

Position Agent::getNextPosition( Map *map ) {
    vector<Position> legalMoves = getLegalMoves( map );
    int r = rand() % legalMoves.size();
    return legalMoves.at(r);
}

void Agent::printStatus() const {
    cout << "{" << endl
         << "\t name: " << name << endl
         << "\t id: " << id << endl
         << "\t position: (" << pos.x << ", " << pos.y << ")" << endl
         << "}" << endl;
}
