#include <cstdlib>
#include <iostream>
#include <vector>

#include "map.h"
#include "randomAgent.h"
#include "game.h"

using std::vector; using std::cout; using std::endl; using std::cin;

Game::Game(int w, int h) {
    map = new Map(w,h);
    hasEnd = false;

    //Agent agent( 1, Position(0,0), "agent", "plate" ); 
    RandomAgent agent( 1, Position(0,0), "agent", "plate" ); 
    map->addObject( agent.getPosition(), agent.getCar() );
    agents.push_back(agent);

    RandomAgent agent2( 2, Position(w-1,h-1), "agent", "plate" ); 
    map->addObject( agent2.getPosition(), agent2.getCar() );
    agents.push_back(agent2);
}

Game::~Game() {
    delete map;
}

void Game::run() {
    for( Agent& agent : agents ) {
        moveAgent(agent);
        map->printMap();
        cin.get();
        cin.sync();
        system("clear");
    }
}

bool Game::moveAgent( Agent& agent ) {

    bool moved = false;
    Position nextPos = agent.getNextPosition( map );
    Position currentPos = agent.getPosition();
    if( currentPos.x == nextPos.x && currentPos.y == nextPos.y ) {
        return false;
    }

    Type nextType = map->at(nextPos)->getType();
    switch( nextType ) {
        case EMPTY: {
            moved = map->moveObject( currentPos, nextPos );
            if( moved ) {
                agent.setPosition( nextPos );
            }
            break;
        }
        case WALL: {
            break;
        }
        case CAR: {
            break;
        }
        case PARK: {
            bool Parked = map->at(nextPos)->join( agent.getCar() );
            if( Parked ) {
                Position generationPoint = Position(0,0);
                moved = map->moveObject( currentPos, generationPoint );
                if( moved ) {
                    agent.setPosition( generationPoint );
                }
            }
            break;
        }
        default: {
            moved = false;
            break;
        }
    }
    return moved;
}


bool Game::shouldTerminate() {
    return hasEnd;
}

void Game::printStatus() const {
}
