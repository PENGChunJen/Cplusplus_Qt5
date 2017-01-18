#include <iostream>

#include "CSVReader.h"
#include "map.h"

using namespace std;

int main( int argc, char* argv[] ) {

    CSVReader csvReader;
    Map map;

    map.printStatus();

    cout << endl << "adding a parking lot data..." << endl;
    Park p1 = {"1", "停車場", {100.0, 200.0}, 200, 150 ,false};
    map.addPark(p1);

    map.printStatus();

    return 0;
}
