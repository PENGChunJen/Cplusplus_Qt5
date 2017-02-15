//#include <algorithm>
#include <iostream>

#include "object.h"
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
    Object *park = new Park("parkID", "parkName", 100, 1, false);
    addObject( Position(width/2, height/2), park );
    
    /* Add Walls */
    for( int i = 0; i < width; ++i ) {
        for( int j = 0; j < height; ++j ) {
            if( i%2 == 1 && j%2 == 1 ) {
                Object *ptr = new Wall();
                addObject( Position(i,j), ptr );
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

void Map::printMap() const {
    for( int i = 0; i < width; ++i ) {
        for( int j = 0; j < height; ++j ) {
            switch( grid[i][j]->getType() ) {
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
                    cout << " ";
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

bool Map::addObject( const Position& newPos, Object *o ) {

    if( isLegal( newPos ) && grid[newPos.x][newPos.y]->getType() == EMPTY ) {

        delete grid[newPos.x][newPos.y];
        grid[newPos.x][newPos.y] = o;
        return true;
    }
    return false;
}

bool Map::moveObject( const Position& currentPos, const Position& newPos ) {

    if( !isLegal(newPos) ) {
        return false;
    }
    if( currentPos.x == newPos.x && currentPos.y == newPos.y ) {
        return false;
    }
    if( grid[currentPos.x][currentPos.y]->getType() != CAR ) {
        return false;
    }


    Object *currentPtr = grid[currentPos.x][currentPos.y];
    Object *newPtr = grid[newPos.x][newPos.y];



    if( newPtr->getType() != EMPTY ) {

        if( newPtr->getType() == PARK ) {
            bool Parked = newPtr->join( currentPtr );
            if( !Parked )
                return false;

            delete currentPtr;
            grid[currentPos.x][currentPos.y] = new Object();
            return true;
        }

        return false;
    }

    swap( grid[currentPos.x][currentPos.y], grid[newPos.x][newPos.y] );
    return true;
}


/*
gridPos Map::findAnEmptyPlace() const{
    for(int i=0; i<w()*h(); i++){
        if(grid[i%h()][i/h()] == EMPTY)
            return gridPos{i%h(),i/h()};
    }
    return gridPos{-1,-1};
}

bool Map::checkNextStep(gridPos &pos, Direction d) const{
    switch (d) {
    case RIGHT:
        if(pos.x != w()-1 && grid[pos.x+1][pos.y] != WALL)
            pos.x++;
        else return false;
        break;
    case DOWN:
        if(pos.y != h()-1 && grid[pos.x][pos.y+1] != WALL)
            pos.y++;
        else return false;
        break;
    case LEFT:
        if(pos.x != 0 && grid[pos.x-1][pos.y] != WALL)
            pos.x--;
        else return false;
        break;
    case UP:
        if(pos.y != 0 && grid[pos.x][pos.y-1] != WALL)
            pos.y--;
        else return false;
        break;
    default:
        return false;
    }

    if(newAgentPos != agentPos)
        channel->updateAgent(agentId, newAgentPos);
    //cout << pos.x << ", " << pos.y << endl;
    return true;
}


void Map::removeCar() {
    //TODO
}

void Map::printStatus(ostream* out){
    if( parks.size() == 0 ) {
        *out << "No Parks in the map" << endl;
        return;
    }

    for( Park& park : parks ) {
        printParkStatus( park , out);
    }
}

void Map::printParkStatus( const Park& park , ostream* out){
    *out << "{" << endl
         << "\tPark : " << park.name << endl
         << "\tid : " << park.id << endl
         << "\tpos : (" << park.pos.x << ", " << park.pos.y << ")" << endl
         << "\tcapacity : " << park.capacity << endl
         << "\tfree : " << park.free << endl
         << "}" << endl;
}
*/
