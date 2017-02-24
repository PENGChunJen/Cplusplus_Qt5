#include <chrono>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "map.h"
#include "randomAgent.h"
#include "game.h"

using std::vector; using std::cout; using std::endl; using std::cin;

Game::Game(int w, int h) {
    mapPtr = new Map(w,h);
    mapPtr->defaultSetting();
    hasEnd = false;

    Agent agent( 1, Position(1,1), "agent", "plate" ); 
    //RandomAgent agent( 1, Position(0,0), "agent", "plate" ); 
    mapPtr->addObject( agent.getPosition(), agent.getCar() );
    agents.push_back(agent);

    RandomAgent agent2( 2, Position(w-2,h-2), "agent", "plate" ); 
    mapPtr->addObject( agent2.getPosition(), agent2.getCar() );
    agents.push_back(agent2);
}

Game::~Game() {
    delete mapPtr;
}

void Game::run() {

    //std::chrono::milliseconds duration(500);
    //std::chrono::time_point<std::chrono::steady_clock> end;
    //end = std::chrono::steady_clock::now() + duration;

    for( Agent& agent : agents ) {
        moveAgent(agent);
        //mapPtr->printMap();
    }

    //while ( std::chrono::steady_clock::now() < end ) {
    //}
}

bool Game::moveAgent( Agent& agent ) {

    bool moved = false;
    Position nextPos = agent.getNextPosition( mapPtr );
    Position currentPos = agent.getPosition();
    if( currentPos.x == nextPos.x && currentPos.y == nextPos.y ) {
        return false;
    }

    Type nextType = mapPtr->at(nextPos)->getType();
    switch( nextType ) {
        case EMPTY: {
            moved = mapPtr->moveObject( currentPos, nextPos );
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
            bool Parked = mapPtr->at(nextPos)->join( agent.getCar() );
            if( Parked ) {
                Position generationPoint = Position(1,1);
                moved = mapPtr->moveObject( currentPos, generationPoint );
                if( moved ) {
                    agent.setPosition( generationPoint );
                }
            }
            break;
        }
        default: {
            moved = false;
        }
    }
    return moved;
}


bool Game::shouldTerminate() {
    return hasEnd;
}

void Game::printStatus() const {
}
