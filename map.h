#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>

using namespace std;

struct Position {
    Position( const double& _x, const double& _y ) 
        :x(_x), y(_y){}

    double x;
    double y;
};

struct Park {
    int id;
    wchar_t *name;
    Position pos;
    int capacity;
    int free;
};

class Map {

public:
    Map(){}
    void addPark( Park p ) { parks.push_back(p); }
    void addCar(); //TODO
    void removeCar(); //TODO
    void printStatus();

private:
    vector<Park> parks;

    void printParkStatus( const Park& park );
};
#endif
