#include <iostream>
#include <vector>

#include "map.h"
#include "randomAgent.h"
#include "game.h"

using std::vector; using std::cout; using std::endl;

Game::Game(int w, int h) {
    map = new Map(w,h);
    map->printMap();

    Agent agent( 1, Position(0,0), "agent", "plate" ); 
    //RandomAgent agent( 1, Position(0,0), "agent", "plate" ); 
    map->addObject( agent.getPosition(), agent.getCar() );
    agents.push_back(agent);
    map->printMap();

    hasEnd = false;
}

Game::~Game() {
    delete map;
}

void Game::run() {

    for( auto it = agents.begin(); it != agents.end(); ++it ) {

        this->map->printMap();
        Position newPos = it->getNextPosition( map );
        this->map->printMap();

        it->printStatus();
        it->getPosition().print();
        cout << "move to";
        newPos.print();


        bool moved = map->moveObject( it->getPosition(), newPos );
        if( moved ) {
            it->setPosition( newPos );
        }
        //map->printMap();
    }
    //hasEnd = true;
}

bool Game::shouldTerminate() {
    return hasEnd;
}

void Game::printStatus() const {
}
