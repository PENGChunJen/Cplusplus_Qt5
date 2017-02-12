#ifndef MAP_H
#define MAP_H

#include "../util/util.h"
#include "object.h"
#include "wall.h"
#include "park.h"
#include "car.h"

using namespace std;

#define TESTSIZE 5

class Map{
public:
    Map( int w, int h );
    Map( string filename );
    ~Map();

    void printMap() const;
    void printStatus() const;

private:
    bool addWall( const int x, const int y );
    //Map(int w=TESTSIZE, int h=TESTSIZE, TWD97 origin, double scale );
    //void updateCar(size_t agentId, Position newPosition);
    //void updatePark(size_t parkId,);

private:
    Object*** grid;
    int width;
    int height;
};
#endif 
