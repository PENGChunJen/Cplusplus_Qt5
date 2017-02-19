#include <iostream>

#include "../util/CSVReader.h"
#include "../src/map.h"
#include "../src/car.h"
#include "../src/park.h"

using std::cout; using std::endl;

int main( int argc, char* argv[] ) {

    Map map(5,5);
    map.defaultSetting();
    map.printMap();

    cout << endl << "adding a parking lot at (0,0)..." << endl;
    Object *park = new Park("parkID", "parkName", 100, 1, false);
    map.addObject( Position(0,0), park );
    map.printMap();

    cout << endl << "adding a car at (2,0)..." << endl;
    Object *car = new Car("owner", "plate");
    map.addObject( Position(2,0), car );
    map.printMap();

    
    bool moved = map.moveObject( Position(2,0), Position(1,0));
    cout << endl << "moving car to (1,0), moved = " << moved << endl;
    map.printMap();
    park->printStatus();

    cout << endl << "moving car to (0,0)..." << endl;
    moved = map.moveObject( Position(1,0), Position(0,0));
    cout << endl << "moving car to (0,0), moved = " << moved << endl;
    map.printMap();
    park->printStatus();

    return 0;
}
