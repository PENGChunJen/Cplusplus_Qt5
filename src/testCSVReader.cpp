#include <iostream>
#include <cmath>
#include <typeinfo>

#include "../util/CSVReader.h"
#include "../src/map.h"
#include "../src/park.h"

using namespace std;

Position WGS84toPosition( double longitude, double latitude, double scale ) {
    double originX = 25.026138;
    double originY = 121.522923;
    int x = int( (latitude - originX) * 110571.0 / scale );
    int y = int( (longitude - originY) * 111320.0 * cos(latitude*M_PI/180.0) / scale );
    return Position(x,y);
}


int main (int argc, char *argv[]) {
    if ( argc != 2 ) {
        cout << "\n\tUsage ./testCSVReader <filename>\n\n";
        return -1;
    }

    char *filename = argv[1];

    //CSVReader csvReader;
    //csvReader.readFile(filename);
    CSVReader csvReader(filename);
    //csvReader.print();
    
    int width = 51;
    int height = 101;
    
    Map map(width, height);

    for( int i = 1; i < csvReader.size(); ++i ) {
        string parkID = csvReader.at(i,0);
        string parkName = csvReader.at(i,1);
        double longitude = std::stod( csvReader.at(i,2) );
        double latitude = std::stod( csvReader.at(i,3) );

        Position pos = WGS84toPosition( longitude, latitude, 50 );
        cout << "adding park" << parkName << " at (" << pos.x << "," << pos.y << ")" << endl;
        if( pos.x >= 0 && pos.x < width && pos.y >= 0 && pos.y < height ) {
            cout << "adding park " << parkName << " at (" << pos.x << "," << pos.y << ")" << endl;
            Park *park = new Park("parkID", "parkName", 100, 1, false);
            map.addObject( pos, park );
        }
    }
    map.defaultSetting();
    map.printMap();
    
}
