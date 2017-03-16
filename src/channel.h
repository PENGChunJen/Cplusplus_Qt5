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
        emit qtDrawCar(game->getKbAgent()->getCar()->getID(),
                       QString::fromStdString(game->getKbAgent()->getCar()->getOwner()),
                       game->getKbAgent()->getPosition().x,
                       game->getKbAgent()->getPosition().y,
                       true);
    }
    void printGameMap(){
        for(int i=0; i<mw(); i++){
            for(int j=0; j<mh(); j++){
                if(game->getMap()->at(i,j)->getType() == CAR){
                    Car* c = (Car*)game->getMap()->at(i,j);
                    emit qtDrawCar(c->getID(), QString::fromStdString(c->getOwner()), i, j, false);
                }
                else{
                    drawObject(game->getMap()->at(i,j)->getID(),
                               game->getMap()->at(i,j)->getType(),
                               i, j);
                    if(game->getMap()->at(i,j)->getType() == PARK){
                        Park* p = (Park*)game->getMap()->at(i,j);
                        setParkFreeNumber(p->getID(), p->getFree());
                    }
                }
            }
        }
    }
signals:
    void qtDrawObject(int id, int type, int x, int y);
    void qtDrawCar(int id, QString owner, int x, int y, bool isKeyAgent);
    void setParkFreeNumber(int id, int free);
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
