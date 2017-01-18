#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>

using namespace std;

struct TWD97 {
    TWD97( const double& _x, const double& _y ) 
        :x(_x), y(_y){}
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
    void printStatus();

private:
    vector<Park> parks;

    void printParkStatus( const Park& park );
};
#endif
