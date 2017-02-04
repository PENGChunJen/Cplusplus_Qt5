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
    Map(int w=TESTSIZE, int h=TESTSIZE);
    void addPark( Park p ) { parks.push_back(p); }
    void addCar(); //TODO
    void removeCar(); //TODO
    void printStatus(ostream* out = &cout);

    int w() const { return mSize.x; }
    int h() const { return mSize.y; }
    bool isGridEmpty(gridPos pos) const{ return (grid[pos.x][pos.y] == EMPTY);}
    bool checkNextStep(gridPos &pos, Direction d) const;
    gridPos findAnEmptyPlace() const;

private:
    vector<Park> parks;
    void printParkStatus(const Park& park , ostream* out);

    int** grid;
    gridPos mSize;
    vector<gridPos> walls;

    friend class Channel;
    //friend class Agent;
    static const unsigned int TESTSIZE = 5; // ugly but temp
};
#endif
