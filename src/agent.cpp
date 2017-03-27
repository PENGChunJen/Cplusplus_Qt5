//#include <cstdlib>
#include <iostream>
#include <queue>
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
    score = 0;
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
        //if( map->isLegal(possiblePos) ) {
        if( map->isPath(possiblePos) ) {
            legalMoves.push_back( possiblePos );
        }
    }

    return legalMoves;
}

Position Agent::getNextPosition( const Map *map ) {

    vector<Position> legalMoves = getLegalMoves( map, agentPos );
    int r = rand() % legalMoves.size();
    Position nextPos = legalMoves.at(r);
    return nextPos;
}

Position Agent::getNearestPark( const Map *map ) {

    Position target = agentPos;
    bool visited[map->getWidth()][map->getHeight()] = {{false}};
    std::queue<Position> queue; 

    visited[agentPos.x][agentPos.y] = true;
    queue.push( agentPos );

    while( !queue.empty() ){
        Position pos = queue.front();
        queue.pop();
        
        if( map->at(pos)->getType() == PARK ) {
            Park *park = (Park*)map->at(pos);
            if( !park->isFull() ) {
                target = pos;
                break;
            }
        }
        vector<Position> adjacents = getLegalMoves( map, pos );
        for( Position &adjacent : adjacents ) {
            if( !visited[adjacent.x][adjacent.y] ) {
                visited[adjacent.x][adjacent.y] = true;
                queue.push(adjacent);
            }
        }
    }
    return target;
}

void Agent::printStatus() const {
    cout << "{" << endl
         << "\t name: " << name << endl
         << "\t id: " << id << endl
         << "\t position: (" << agentPos.x << ", " << agentPos.y << ")" << endl
         << "}" << endl;
}

void Agent::printMoves( const vector<Position>& legalMoves, const Position& nextPos ) const {
    cout << "legalMove: ";
    for( const Position& p : legalMoves ) {
        cout << p << ",";
    }
    cout << "\b " << endl
         <<"choseMove: " << nextPos << endl;
}
