#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>

using namespace std;

struct TWD97 {
    double x;
    double y;
};

struct Park {
    string id;
    string name;
    TWD97 pos;
    int capacity;
    int free;
    bool isMrt; 
};

class Map {

public:
    Map(){}
    void addPark( Park p ) { parks.push_back(p); }
    void addCar(); //TODO
    void removeCar(); //TODO
    void printStatus(ostream* out = &cout);

private:
    vector<Park> parks;

    void printParkStatus( const Park& park , ostream* out);
};
#endif
