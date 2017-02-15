#include <iostream>
#include <vector>

#include "map.h"
#include "randomAgent.h"
#include "game.h"

using std::vector; using std::cout; using std::endl;

Game::Game(int w, int h) {
    map = new Map(w,h);
    hasEnd = false;

    Agent agent( 1, Position(0,0), "agent", "plate" ); 
    //RandomAgent agent( 1, Position(0,0), "agent", "plate" ); 
    map->addObject( agent.getPosition(), agent.getCar() );
    agents.push_back(agent);
}

Game::~Game() {
    delete map;
}

void Game::run() {

    for( auto it = agents.begin(); it != agents.end(); ++it ) {

        Position currentPos = it->getPosition();
        Position newPos = it->getNextPosition( map );

        it->printStatus();
        //cout << currentPos << " move to " << newPos << endl;

        bool moved = map->moveObject( currentPos, newPos );
        if( moved ) {
            it->setPosition( newPos );
        }
        //map->printMap();
    }
}

bool Game::shouldTerminate() {
    return hasEnd;
}

void Game::printStatus() const {
}
