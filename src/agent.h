#ifndef AGENT_H 
#define AGENT_H

#include "map.h"
#include "car.h"

class Agent {

public:
    Agent(size_t _id, const Position& _pos, const std::string &_name, const std::string &_plate);
    ~Agent();

    void setPosition( Position newPos ) { pos = newPos; }

    size_t getId(){ return id; }
    std::string getName(){ return name; }
    Position getPosition(){ return pos;}
    Car *getCar() { return car; }

    std::vector<Position> getLegalMoves( Map* map ); 
    void printStatus() const;

    Position getNextPosition( Map* map );
    //virtual Position getNextPosition( Map* map );

protected:
    size_t id;
    Position pos;
    std::string name;
    Car *car; 
};

#endif // AGENT_H
