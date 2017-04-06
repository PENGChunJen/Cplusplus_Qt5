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
                else if(game->getMap()->at(i,j)->getType() == WALL){
                    int show = getWallShow(game->getMap(), i, j);
                    Wall* w = (Wall*)game->getMap()->at(i,j);
                    emit qtDrawWall(w->getID(), show, i, j);
                }
                else if(game->getMap()->at(i,j)->getType() == PARK){
                    Park* p = (Park*)game->getMap()->at(i,j);
                    emit qtDrawPark(p->getID(), p->getType(), i, j, p->getFree());
                }
            }
        }
    }

signals:
    void qtDrawPark(int id, int type, int x, int y, int free);
    void qtDrawCar(int id, QString owner, int x, int y, bool isKeyAgent);
    void qtDrawWall(int id, int show, int x, int y);

public slots:
    void onGameRun(){
        game->run();
        printGameMap();
    }
    void onKbAgentMove(int d){
        game->getKbAgent()->setDirection(d);
    }

private:
    int getWallShow(Map* m, int x, int y){
        int s = 0;
        if(y != 0 && m->at(x,y-1)->getType() == WALL){
            s += 1;
        }
        if(x != 0 && m->at(x-1,y)->getType() == WALL){
            s += 2;
        }
        if(y != m->getHeight()-1 && m->at(x,y+1)->getType() == WALL){
            s += 4;
        }
        if(x != m->getWidth()-1 && m->at(x+1,y)->getType() == WALL){
            s += 8;
        }
        return s;
    }

    Game* game;
};

#endif // CHANNEL_H
