#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>

#include "channel.h"
#include "object.h"

using namespace std;

#define TESTSIZE 5

class Map{
public:
    Map(Channel* _channel, int w=TESTSIZE, int h=TESTSIZE, TWD97 origin, double scale ){
        channel = _channel;
        width = w;
        height = h;
    }

    Channel* getChannel (){ return channel; }
    //void updateAgent(int agentId, Position newPosition);
    //void updatePark(int parkId, int );

private:
    Channel* channel;
    void printParkStatus(const Park& park , ostream* out); 

    Object** grid;
    int width;
    int height;
};
#endif
