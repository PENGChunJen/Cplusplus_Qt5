#ifndef AGENT_H 
#define AGENT_H

#include <vector>

#include "map.h"
#include "car.h"

class Agent {

public:
    Agent(size_t _id, const Position& _pos, const std::string &_name, const std::string &_plate);
    ~Agent();


    size_t getId(){ return id; }
    std::string getName() const { return name; }
    Position getPosition() const { return agentPos; }
    Car *getCar() { return car; }

    void setPosition( Position newPos ) { agentPos = newPos; }
    std::vector<Position> getLegalMoves( const Map *map ); 

    void printStatus() const;

    virtual Position getNextPosition( const Map* map );
    //virtual Position getNextPosition();

protected:
    size_t id;
    Position agentPos;
    std::string name;
    Car *car; 
};

#endif // AGENT_H
