#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
using namespace std;

struct gridPos {
    int x;
    int y;
};

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

enum Direction{
    RIGHT,
    DOWN,
    LEFT,
    UP
};

class Channel;

class Map{
    enum Status{
        EMPTY,
        AGENT,
        PARK,
        WALL
    };

public:
    Map();
    void addPark( Park p ) { parks.push_back(p); }
    void addCar(); //TODO
    void removeCar(); //TODO
    void printStatus(ostream* out = &cout);

    int w() const { return mSize.x; }
    int h() const { return mSize.y; }
    int ax() const { return agentPos.x; }
    int ay() const { return agentPos.y; }
    bool agentMove(Direction d);

private:
    static const unsigned int TESTSIZE = 5; // ugly but temp

    vector<Park> parks;
    void printParkStatus( const Park& park , ostream* out);

    enum Status grid[TESTSIZE][TESTSIZE];
    gridPos mSize{TESTSIZE, TESTSIZE};
    gridPos agentPos{0, 0};
    vector<gridPos> walls;

    friend class Channel;
};
#endif
