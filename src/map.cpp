#include <algorithm>
#include <iostream>
#include <iomanip>

#include "wall.h"
#include "park.h"
#include "map.h"

using std::cout; using std::endl; using std::string;

Map::Map(int w, int h, const string config ) {

    width = w;
    height = h;
    
    if( config == "dfs" ) {
        dfsInitialization();
    }
    else {
        defaultInitialization();
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

void Map::dfsInitialization() {

    /* Add all WALL Objects */
    grid = new Object**[width];
    for( int i = 0; i < width; ++i ) {
        grid[i] = new Object*[height];
        for( int j = 0; j < height; ++j ) {
            grid[i][j] = new Wall();
        }
    }
    
    dfs( Position(width/2-1,height/2-1) ); 

    /* Add a Park at center */
    Object *park = new Park("parkName", 100, 1, false);
    addObject( Position(width/2, height/2), park );
    
}

void Map::dfs( const Position& pos ) {
    Object *empty = new Object();
    addObject( pos, empty );
    
    int sequence[4] = {0, 1, 2, 3};
    std::random_shuffle( sequence, sequence+4 );

    for( int& i : sequence ) {
        Position nextPos = getAdjacent( pos, i );
        if( inBound(nextPos) && grid[nextPos.x][nextPos.y]->getType() == WALL ) {
            Position middle( (pos.x + nextPos.x)/2, (pos.y + nextPos.y)/2 );
            Object *empty = new Object();
            addObject( middle, empty );
            dfs(nextPos);
        }
    }

}

Position Map::getAdjacent( const Position& pos, int r ) {
    if(r == 0) {
        return Position( pos.x-2, pos.y );
    }
    else if(r == 1) {
        return Position( pos.x+2, pos.y );
    }
    else if(r == 2) {
        return Position( pos.x, pos.y-2 );
    }
    else {
        return Position( pos.x, pos.y+2 );
    }
}


void Map::defaultInitialization() {

    /* Add all EMPTY Objects */
    grid = new Object**[width];
    for( int i = 0; i < width; ++i ) {
        grid[i] = new Object*[height];
        for( int j = 0; j < height; ++j ) {
            grid[i][j] = new Object();
        }
    }

    /* Add Bondary Walls */
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
    
    /* Add Walls */
    for( int i = 0; i < width; ++i ) {
        for( int j = 0; j < height; ++j ) {
            if( i%2 == 0 && j%2 == 0 ) {
                Object *ptr = new Wall();
                addObject( Position(i,j), ptr );
            }
        } 
    }

    /* Add a Park at center */
    Object *park = new Park("parkName", 100, 1, false);
    addObject( Position(width/2, height/2), park );

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

bool Map::inBound( const Position& newPos ) const {
    if( newPos.x >= width || newPos.x < 0 || newPos.y >= height || newPos.y < 0 ) {
        return false;
    }
    return true;
}

bool Map::isLegal( const Position& newPos ) const {
    if( !inBound(newPos) ) {
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

    //if( isLegal( newPos ) && grid[newPos.x][newPos.y]->getType() == EMPTY ) {
    if( inBound( newPos ) ) {
        delete grid[newPos.x][newPos.y];
        grid[newPos.x][newPos.y] = o;
        return true;
    }
    return false;
}

bool Map::moveObject( const Position& currentPos, const Position& nextPos ) {

    if( canMove(currentPos) && canMove(nextPos) ) {
        std::swap( grid[currentPos.x][currentPos.y], grid[nextPos.x][nextPos.y] );
        return true;
    }
    return false;
}
