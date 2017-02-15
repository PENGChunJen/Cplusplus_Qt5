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
    delete car;
}

vector<Position> Agent::getLegalMoves( const Map *map ) {

    // Difference between constructor, reserve(), resize() 
    Position currentPos( agentPos.x, agentPos.y );
    vector<Position> possibleMoves;
    vector<Position> legalMoves;

    possibleMoves.push_back( Position( currentPos.x, currentPos.y ) );
    possibleMoves.push_back( Position( currentPos.x+1, currentPos.y ) );
    cout << "b: " << endl;
    map->printMap();


    Position p( currentPos.x-1, currentPos.y );
    cout << "a: " << endl;
    map->printMap();


    possibleMoves.push_back(p);
    cout << "c: " << endl;
    map->printMap();

    /*
    possibleMoves.push_back( Position( currentPos.x-1, currentPos.y ) );
    possibleMoves.push_back( Position( currentPos.x, currentPos.y-1 ) );
    possibleMoves.push_back( Position( currentPos.x, currentPos.y+1 ) );
    */

    for( auto it = possibleMoves.begin(); it != possibleMoves.end(); ++it ) {

        Position nextPos = *it;

        cout << "checkMove: " << nextPos.x << ", " << nextPos.y << endl;
        map->printMap();
        if( map->isLegal(nextPos) ) {
            cout << "legalMove: " << nextPos.x << ", " << nextPos.y << endl;
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
         << "\t position: (" << agentPos.x << ", " << agentPos.y << ")" << endl
         << "}" << endl;
}
