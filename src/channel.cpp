#include "channel.h"

void GameChannel::run(){
    game->run();
}

void GameChannel::printGameMap(){
    for(int i=0; i<mw(); i++){
        for(int j=0; j<mh(); j++){
            drawObject(game->getMap()->at(i,j)->getID(),
                       game->getMap()->at(i,j)->getType(),
                       i, j);
        }
    }
}
