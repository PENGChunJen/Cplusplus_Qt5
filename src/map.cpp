#include "map.h"

using namespace std;

Map::Map() {
    for(int i=0; i<TESTSIZE*TESTSIZE; i++)
        grid[i/TESTSIZE][i%TESTSIZE] = EMPTY;

    walls.push_back(gridPos{1,1});
    walls.push_back(gridPos{1,3});
    walls.push_back(gridPos{3,1});
    walls.push_back(gridPos{3,3});

    grid[agentPos.x][agentPos.y] = AGENT;
    for(int i=0; i<walls.size(); i++)
        grid[walls[i].x][walls[i].y] = WALL;
}

bool Map::agentMove(Direction d){
    switch (d) {
    case RIGHT:
        if(agentPos.x != TESTSIZE-1 && grid[agentPos.x+1][agentPos.y] != WALL)
            agentPos.x++;
        else return false;
        break;
    case DOWN:
        if(agentPos.y != TESTSIZE-1 && grid[agentPos.x][agentPos.y+1] != WALL)
            agentPos.y++;
        else return false;
        break;
    case LEFT:
        if(agentPos.x != 0 && grid[agentPos.x-1][agentPos.y] != WALL)
            agentPos.x--;
        else return false;
        break;
    case UP:
        if(agentPos.y != 0 && grid[agentPos.x][agentPos.y-1] != WALL)
            agentPos.y--;
        else return false;
        break;
    default:
        return false;
    }
    //cout << agentPos.x << ", " << agentPos.y << endl;
    return true;
}

void Map::addCar() {
    //TODO
}

void Map::removeCar() {
    //TODO
}

void Map::printStatus(ostream* out) {
    if( parks.size() == 0 ) {
        *out << "No Parks in the map" << endl;
        return;
    }


    for( Park& park : parks ) {
        printParkStatus( park , out);
    }

}

void Map::printParkStatus( const Park& park , ostream* out) {
    *out << "{" << endl
         << "\tPark : " << park.name << endl
         << "\tid : " << park.id << endl
         << "\tpos : (" << park.pos.x << ", " << park.pos.y << ")" << endl
         << "\tcapacity : " << park.capacity << endl
         << "\tfree : " << park.free << endl
         << "}" << endl;
}
