#include "map.h"

using namespace std;

Map::Map(int w, int h) {
    mSize.x = w;
    mSize.y = h;
    Channel channel();

    grid = new int*[w];
    for(int i=0; i<w; i++){
        grid[i] = new int[h];
    }

    for(int i=0; i<w*h; i++)
        grid[i%h][i/h] = EMPTY;

    // for test
    for(int i=1; i<w; i+=2){
        for(int j=1; j<h; j+=2){
            walls.push_back(gridPos{i,j});
        }
    }

    for(int i=0; i<walls.size(); i++)
        grid[walls[i].x][walls[i].y] = WALL;

    channel->loadMap(grid);
}

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

void Map::addCar() {
    //TODO
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
