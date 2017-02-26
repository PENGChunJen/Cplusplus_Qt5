#ifndef CHANNEL_H
#define CHANNEL_H

#include <QObject>
#include "game.h"

class GameChannel : public QObject{
    Q_OBJECT
    Q_PROPERTY(int mw READ mw)
    Q_PROPERTY(int mh READ mh)
public:
    GameChannel (Game* g){
        game = g;
    }

    int mw() const { return game->getMap()->getWidth(); }
    int mh() const { return game->getMap()->getHeight(); }

    void drawKbCar(){
        emit registerKbAgent(game->getKbAgent()->getCar()->getID(),
                             game->getKbAgent()->getPosition().x,
                             game->getKbAgent()->getPosition().y);
    }
    void printGameMap(){
        for(int i=0; i<mw(); i++){
            for(int j=0; j<mh(); j++){
                drawObject(game->getMap()->at(i,j)->getID(),
                           game->getMap()->at(i,j)->getType(),
                           i, j);
            }
        }
    }
signals:
    void qtDrawObject(int id, int type, int x, int y);
    void registerKbAgent(int id, int x, int y);
public slots:
    void onGameRun(){
        game->run();
        printGameMap();
    }
    void onKbAgentMove(int d){
        game->getKbAgent()->setDirection(d);
    }
private:
    void drawObject(int id, int type, int x, int y){
        emit qtDrawObject(id, type, x, y);
    }

    Game* game;
};

#endif // CHANNEL_H
