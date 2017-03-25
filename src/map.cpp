#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>

#include "wall.h"
#include "map.h"

using std::cerr; using std::cout; using std::endl; 
using std::string; using std::vector;

Map::Map(int w, int h, const string& config ) {

    width = w;
    height = h;
    
    if( config == "dfs" ) {
        dfsInitialization();
    }
    else {
        defaultInitialization();
    }
}

Map::Map(const string& filename) {

    std::ifstream inFile( filename );
    string line;
    vector<string> graph;

    if( !inFile.is_open() ) {
        cerr << "Cannot open file " << filename << endl;
    }
    else {

        /* Count width and height from txt file */
        width = 0;
        while( std::getline( inFile, line ) ) {
            graph.push_back(line);
            ++width;
        }
        height = graph.front().length();
    
        /* Add all WALL Objects */
        grid = new Object**[width];
        for( int i = 0; i < width; ++i ) {
            grid[i] = new Object*[height];
            for( int j = 0; j < height; ++j ) {
                if( graph.at(i).at(j) == '#' ) {
                    grid[i][j] = new Wall();
                }
                else {
                    grid[i][j] = new Object();
                }
            }
        }
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
    
}

void Map::dfs( const Position& pos ) {

    Object *empty = new Object();
    addObject( pos, empty );
    
    Direction directions[4] = {North, South, East, West};
    std::random_shuffle( directions, directions+5 );

    for( Direction& direction : directions ) {
        Position nextPos = pos.getAdjacent( direction, 2 );
        if( inBound(nextPos) && grid[nextPos.x][nextPos.y]->getType() == WALL ) {
            Position middle( (pos.x + nextPos.x)/2, (pos.y + nextPos.y)/2 );
            Object *empty = new Object();
            addObject( middle, empty );
            dfs(nextPos);
        }
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

bool Map::isLegal( const Position& pos ) const {

    if( !inBound(pos) ) {
        return false;
    }

    Type t = grid[pos.x][pos.y]->getType();
    if( t == WALL || t == CAR ) {
        return false;
    }
    return true;
}

bool Map::isPath( const Position& pos ) const {

    if( !inBound(pos) ) {
        return false;
    }

    Type t = grid[pos.x][pos.y]->getType();
    if( t == WALL ) {
        return false;
    }
    else if ( t == PARK ) {
        Park* park = (Park*)grid[pos.x][pos.y];
        if( park->isFull() ){
            return false;
        }
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
