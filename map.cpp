#include "map.h"

using namespace std;
/*
Map::Map() {
    //TODO
}
*/

void Map::addCar() {
    //TODO
}

void Map::removeCar() {
    //TODO
}

void Map::printStatus() {
    if( parks.size() == 0 ) {
        cout << "No Parks in the map" << endl;
        return;
    }


    for( Park& park : parks ) {
        printParkStatus( park );
    }

}

void Map::printParkStatus( const Park& park ) {
    cout << "{" << endl
         << "\tPark : " << park.name << endl
         << "\tid : " << park.id << endl
         << "\tpos : (" << park.pos.x << ", " << park.pos.y << ")" << endl
         << "\tcapacity : " << park.capacity << endl
         << "\tfree : " << park.free << endl
         << "}" << endl;
}
