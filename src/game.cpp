#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "map.h"

#include "data.h"
#include "park.h"

#include "rightAgent.h"
#include "dfsAgent.h"
#include "bfsAgent.h"

#include "game.h"

using std::cout; using std::endl; using std::cin;
using std::vector; using std::string; 

Game::Game() {
    //mapPtr = new Map(49, 49);
    //mapPtr = new Map(17, 17, "dfs");
    mapPtr = new Map("../data/sampleMap.txt");

    //addParks();
    addParks("realData");

    addAgents();
}

Game::~Game() {
    delete mapPtr;
}

void Game::addParks( const string& config ) {
    
    if( config == "realData" ) {
        Data d;
        for( auto it = d.parks.begin(); it != d.parks.end(); ++it ) {
    
            std::map<std::string, std::string> &data = it->second;
    
            /* Convert data type for Park */
            string id = data["id"];
            string name = data["name"];
            int capacity = std::max( 0, std::stoi( data["capacity"] ) );
            int available = std::min( capacity, std::max( 0, std::stoi( data["available"] ) ) );
            bool isMRT = ( data["isMRT"] == "true" ) ? true : false;
    
            /* Transform tw97 to map coordinate */
            double tw97x = std::stod( data["tw97x"] );
            double tw97y = std::stod( data["tw97y"] );
            Position pos = tw97ToPosition( 304525.666, 2769543.80, tw97x, tw97y, 20 );
    
            /* Add park on map and in parks, if it locates in the map */
            if( mapPtr->inBound( pos ) ) {
                Park *park = new Park( id, name, capacity, available, isMRT );
                mapPtr->addObject( pos, park );
                parks.push_back(park);
            }
        }
    }
    else {
        Park *park = new Park("id", "name", 10, 10, false);
        Position pos( mapPtr->getWidth()/2, mapPtr->getHeight()/2 ); 
        mapPtr->addObject( pos, park );
        parks.push_back(park);
    }
}

Position Game::tw97ToPosition( const double originX, const double originY, 
                               const double tw97x, const double tw97y, const double scale ) {
    int x = (tw97x-originX)/scale;
    int y = (tw97y-originY)/scale;
    return Position(x,y);
}

Position Game::generationPosition() {
    Position pos;
    do {
        int x = rand() % mapPtr->getWidth();
        int y = rand() % mapPtr->getHeight();
        pos = Position(x,y);
    } while( mapPtr->at(pos)->getType() != EMPTY );
    return pos;
}

void Game::addAgents() {     



    kbAgent = new KeyboardAgent( 1, Position(1,1), "Me", "plate" );
    mapPtr->addObject( kbAgent->getPosition(), kbAgent->getCar() );
    agents.push_back(kbAgent);

    addNPC();

}
void Game::addNPC() {

    int w = mapPtr->getWidth();
    int h = mapPtr->getHeight();

    Agent* agent = new Agent( 2, Position(1,h-2), "default Agent", "plate" );
    mapPtr->addObject( agent->getPosition(), agent->getCar() );
    agents.push_back(agent);

    RightAgent* rightAgent = new RightAgent( 3, Position(w-2,h-2), "right Agent", "plate" );
    mapPtr->addObject( rightAgent->getPosition(), rightAgent->getCar() );
    agents.push_back(rightAgent);

    DFSAgent* dfsAgent = new DFSAgent( 4, generationPosition(), "DFS Agent", "plate" );
    mapPtr->addObject( dfsAgent->getPosition(), dfsAgent->getCar() );
    agents.push_back(dfsAgent);

    BFSAgent* bfsAgent = new BFSAgent( 5, generationPosition(), "BFS Agent", "plate" );
    mapPtr->addObject( bfsAgent->getPosition(), bfsAgent->getCar() );
    agents.push_back(bfsAgent);

}

void Game::run() {
    for( Agent* agent : agents ) {
        moveAgent(agent);
    }
    std::sort(agents.begin(), agents.end(),
        [](const Agent *left, const Agent *right) {
            return left->getScore() > right->getScore();
    });
    //printStatus();
}

bool Game::moveAgent( Agent* agent ) {

    bool moved = false;
    Position nextPos = agent->getNextPosition( mapPtr );
    Position currentPos = agent->getPosition();
    if( currentPos == nextPos ) {
        return false;
    }

    Type nextType = mapPtr->at(nextPos)->getType();
    switch( nextType ) {
        case EMPTY: {
            moved = mapPtr->moveObject( currentPos, nextPos );
            if( moved ) {
                agent->setPosition( nextPos );
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
            Park* parkPtr = (Park*)mapPtr->at(nextPos);
            bool Parked = parkPtr->join( agent->getCar() );
            if( Parked ) {
                Position emptyPos = generationPosition();
                moved = mapPtr->moveObject( currentPos, emptyPos );
                if( moved ) {
                    agent->setPosition( emptyPos );
                    if(parkPtr->hasBonus()) {
                        agent->addScore(10);
                    }
                    else {
                        agent->addScore(1);
                    }
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
    for( Park* park : parks ) {
        if( !park->isFull() ) {
            return false;
        }
    }
    return true;
}

void Game::printStatus() const {
    cout << " ============================" << endl
         << "||        Score Board       ||" << endl
         << " ============================" << endl;

    for( Agent* agent : agents ) {
        cout << agent->getName() << ":" << agent->getScore() << endl;
    }
    cout << " ============================" << endl << endl;

}
