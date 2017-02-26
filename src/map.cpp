//#include <algorithm>
#include <iostream>
#include <iomanip>

#include "wall.h"
#include "park.h"
#include "map.h"

using std::cout; using std::endl; using std::swap;

Map::Map(int w, int h) {

    width = w;
    height = h;
    
    /* Add all EMPTY Objects */
    grid = new Object**[width];
    for( int i = 0; i < width; ++i ) {
        grid[i] = new Object*[height];
        for( int j = 0; j < height; ++j ) {
            grid[i][j] = new Object();
        }
    }

    /* Add Parks at center */
    Object *park = new Park("parkName", 100, 1, false);
    addObject( Position(width/2, height/2), park );
    

    /* Add Walls */
    for( int i = 0; i < width; ++i ) {
        Object *ptr = new Wall();
        addObject( Position(i,0), ptr );

        ptr = new Wall();
        addObject( Position(i,height-1), ptr );
    }
    for( int j = 0; j < height; ++j ) {
        Object *ptr = new Wall();
        addObject( Position(0,j), ptr );

        ptr = new Wall();
        addObject( Position(width-1,j), ptr );
    }
}

Map::~Map() {
    for( int i = 0; i < width; ++i ) {
        for( int j = 0; j < height; ++j ) {
            delete grid[i][j];
        }
        delete [] grid[i];
    }
    delete [] grid;
}

void Map::defaultSetting() {

    /* Add Parks at center */
    Object *park = new Park("parkName", 100, 1, false);
    addObject( Position(width/2, height/2), park );
    
    /* Add Walls */
    for( int i = 0; i < width; ++i ) {
        for( int j = 0; j < height; ++j ) {
            if( i%2 == 0 && j%2 == 0 ) {
                Object *ptr = new Wall();
                addObject( Position(i,j), ptr );
            }
        } 
    }
}

void Map::printMap() const {
    for( int i = 0; i < width; ++i ) {
        for( int j = 0; j < height; ++j ) {
            switch( grid[i][j]->getType() ) {
                case EMPTY:
                    cout << " ";
                    break;
                case WALL:
                    cout << "#";
                    break;
                case PARK:
                    cout << "P";
                    break;
                case CAR:
                    cout << "C";
                    break;
                default:
                    cout << "X";
            }
        }
        cout << endl;
    }
}

bool Map::isLegal( const Position& newPos ) const {
    if( newPos.x >= width || newPos.x < 0 || newPos.y >= height || newPos.y < 0 ) {
        return false;
    }
    if( grid[newPos.x][newPos.y]->getType() == WALL ) {
        return false;
    }
    return true;
}

bool Map::canMove( const Position& pos ) const {
    Type t = grid[pos.x][pos.y]->getType();
    if( t == EMPTY || t == CAR ) {
        return true;
    }
    return false;
}

bool Map::addObject( const Position& newPos, Object *o ) {

    if( isLegal( newPos ) && grid[newPos.x][newPos.y]->getType() == EMPTY ) {
        delete grid[newPos.x][newPos.y];
        grid[newPos.x][newPos.y] = o;
        return true;
    }
    return false;
}

bool Map::moveObject( const Position& currentPos, const Position& nextPos ) {

    if( canMove(currentPos) && canMove(nextPos) ) {
        swap( grid[currentPos.x][currentPos.y], grid[nextPos.x][nextPos.y] );
        return true;
    }
    return false;
}
