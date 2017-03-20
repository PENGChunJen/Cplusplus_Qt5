#include <cstdlib>
#include "position.h"

Position Position::getAdjacent( const Direction &direction, const int &len ) const {
    if(direction == North) {
        return Position( x-len, y );
    }
    else if(direction == East) {
        return Position( x, y+len );
    }
    else if(direction == South) {
        return Position( x+len, y );
    }
    else if(direction == West) {
        return Position( x, y-len );
    }
    else {
        return Position( x, y );
    }
}

double Position::manhattanDistance( const Position &target ) {
    return std::abs(x-target.x)+std::abs(y-target.y);
}
/*
std::ostream& operator<< ( std::ostream &o, const Direction &direction ) {
    switch( direction ) {
        case North:
            o << "North";
            break;
        case East:
            o << "East";
            break;
        case South:
            o << "South";
            break;
        case West:
            o << "West";
            break;
        default:
            break;
    }
    return o;
}
*/
