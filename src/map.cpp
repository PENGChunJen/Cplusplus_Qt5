#include <iostream>
#include "map.h"

using namespace std;

Map::Map(int w, int h) {

    width = w;
    height = h;
    
    grid = new Object**[width];
    for( int i = 0; i < width; ++i ) {
        grid[i] = new Object*[height];
        for( int j = 0; j < height; ++j ) {
            grid[i][j] = new Object();
        }
    }
    
    for( int i = 0; i < width; ++i ) {
        for( int j = 0; j < height; ++j ) {
            if( i%2 == 1 && j%2 == 1 ) {
                Position pos = {i, j};
                Object *ptr = new Wall();
                addObject( pos, ptr );
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

bool Map::addObject( const Position& pos, Object *o ) {
    if( grid[pos.x][pos.y]->getType() != EMPTY ) {
        return false;
    }

    delete grid[pos.x][pos.y];
    grid[pos.x][pos.y] = o;

    return true;
}

bool Map::moveObject( const Position& currentPos, const Position& newPos ) {

    Object *currentPtr = grid[currentPos.x][currentPos.y];
    Object *newPtr = grid[newPos.x][newPos.y];

    if( currentPtr->getType() != CAR ) {
        return false;
    }

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
