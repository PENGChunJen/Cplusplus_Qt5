#ifndef MAP_H
#define MAP_H

#include <iostream>
#include "object.h"

using std::cout; using std::endl;

struct Position {
    Position() { x = 0; y = 0; }
    Position(int _x, int _y) { x = _x; y = _y; }
    void print() { cout << "(" << x << ", " << y << ")" << endl; }
    int x;
    int y;
};

struct TWD97 {
    TWD97(); 
    TWD97(double _x, double _y) { x = _x; y = _y; }
    double x;
    double y;
};

class Map{
public:
    Map( int w, int h );
    Map( std::string filename );
    ~Map();

    void printMap() const;
    void printStatus() const;

    bool addObject( const Position& pos, Object *o );
    bool moveObject( const Position& currentPos, const Position& newPos ); 
    bool isLegal( const Position& pos );

    //Map(int w=TESTSIZE, int h=TESTSIZE, TWD97 origin, double scale );
    //void updateCar(size_t agentId, Position newPosition);
    //void updatePark(size_t parkId,);

private:
    Object*** grid;
    int width;
    int height;
};

#endif // MAP_H

