#ifndef MAP_H
#define MAP_H

#include "position.h"
#include "object.h"

/*
struct TWD97 {
    TWD97(); 
    TWD97(double _x, double _y) { x = _x; y = _y; }
    double x;
    double y;
};
*/

class Map{
public:
    Map( int w, int h );
    Map( std::string filename );
    ~Map();

    void printMap() const;
    void printStatus() const;

    Object* at( const Position& pos ) { return grid[pos.x][pos.y]; }

    void defaultSetting();
    bool isLegal( const Position& pos ) const;
    bool canMove( const Position& pos ) const;

    bool addObject( const Position& pos, Object *o );
    bool moveObject( const Position& currentPos, const Position& newPos ); 


    //Map(int w=TESTSIZE, int h=TESTSIZE, TWD97 origin, double scale );
    //void updateCar(size_t agentId, Position newPosition);
    //void updatePark(size_t parkId,);

private:
    Object*** grid;
    int width;
    int height;
};

#endif // MAP_H

