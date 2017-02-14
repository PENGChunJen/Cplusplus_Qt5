#include <cstdlib>
#include <iostream>

#include "../src/game.h"

#define KB_UP 72
#define KB_DOWN 80 
#define KB_LEFT 75 
#define KB_RIGHT 77
#define KB_ESCAPE 27

using namespace std;

int main( int argc, char* argv[] ) {

    Game game(9,9);

    while( !game.shouldTerminate() ) {

        game.printMap();

        game.run();
        cin.get();
        cin.sync();
    }

    return 0;
}
