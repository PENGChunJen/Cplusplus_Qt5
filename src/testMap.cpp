#include <cstdlib>
#include <iostream>

#include "../util/CSVReader.h"
#include "../src/map.h"
#include "../src/car.h"
#include "../src/park.h"

#define KB_UP 72
#define KB_DOWN 80 
#define KB_LEFT 75 
#define KB_RIGHT 77
#define KB_ESCAPE 27

using namespace std;

int main( int argc, char* argv[] ) {

    //CSVReader csvReader;
    Map map(9,9);
    map.printMap();

    cout << endl << "adding a parking lot..." << endl;
    Object *park = new Park("parkName", 100, 1, false);
    map.addObject( Position(0,0), park );
    map.printMap();

    cout << endl << "adding a car..." << endl;
    Object *car = new Car("owner", "plate");
    map.addObject( Position(2,0), car );
    map.printMap();

    cout << endl << "moving a car..." << endl;
    map.moveObject( Position(2,0), Position(1,0));
    map.printMap();
    park->printStatus();
    car->printStatus();

    cout << endl << "moving a car..." << endl;
    map.moveObject( Position(1,0), Position(0,0));
    map.printMap();
    park->printStatus();

    return 0;
}
