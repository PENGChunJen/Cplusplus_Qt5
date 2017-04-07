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
                if(game->getMap()->at(i,j)->getType() == WALL){
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

    void printGameCars(){
        for(int i=0; i<mw(); i++){
            for(int j=0; j<mh(); j++){
                if(game->getMap()->at(i,j)->getType() == CAR){
                    Car* c = (Car*)game->getMap()->at(i,j);
                    emit qtDrawCar(c->getID(), QString::fromStdString(c->getOwner()), i, j, false);
                }
            }
        }
    }

signals:
    void qtDrawPark(int id, int type, int x, int y, int free);
    void qtDrawCar(int id, QString owner, int x, int y, bool isKeyAgent);
    void qtDrawWall(int id, int show, int x, int y);
    void qtSBRenew(int id, int rank, QString name, int score);
public slots:
    void onGameRun(){
        game->run();
        printGameMap();
        printGameCars();
        scoreboardRenew();
    }
    void onKbAgentMove(int d){
        game->getKbAgent()->setDirection(d);
    }

private:
    void scoreboardRenew(){
        int s = game->getAgents().size();
        for(int i=0; i < s; i++){
            emit qtSBRenew(game->getAgents()[i]->getId(), i+1,
                           QString::fromStdString(game->getAgents()[i]->getName()),
                           game->getAgents()[i]->getScore());
        }
    }

    int getWallShow(Map* map, int x, int y){
        int s = 0;
        if(y != 0 && map->at(x,y-1)->getType() == WALL){
            s += 1;
        }
        if(x != 0 && map->at(x-1,y)->getType() == WALL){
            s += 2;
        }
        if(y != map->getHeight()-1 && map->at(x,y+1)->getType() == WALL){
            s += 4;
        }
        if(x != map->getWidth()-1 && map->at(x+1,y)->getType() == WALL){
            s += 8;
        }
        if( (s&1) && (s&2) && map->at(x-1,y-1)->getType() == WALL ){
            s += 16;
        }
        if( (s&2) && (s&4) && map->at(x-1,y+1)->getType() == WALL ){
            s += 32;
        }
        if( (s&4) && (s&8) && map->at(x+1,y+1)->getType() == WALL ){
            s += 64;
        }
        if( (s&8) && (s&1) && map->at(x+1,y-1)->getType() == WALL ){
            s += 128;
        }
        return s;
    }

    Game* game;
};

#endif // CHANNEL_H
