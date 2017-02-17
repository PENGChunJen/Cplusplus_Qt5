#include <cstdlib>
#include <ctime>
#include <iostream>

#include "../src/game.h"

#define KB_UP 72
#define KB_DOWN 80 
#define KB_LEFT 75 
#define KB_RIGHT 77
#define KB_ESCAPE 27

using std::srand; using std::time; using std::cin;

int main( int argc, char* argv[] ) {

    srand( time(NULL) );
    Game game(9,9);

    while( !game.shouldTerminate() ) {
        game.run();
        //cin.get();
        //cin.sync();
    }

    return 0;
}
