#ifndef POSITION_H
#define POSITION_H

#include <iostream>

enum Direction{
    North,
    East,
    South,
    West
};

class Position {

public:
    Position(){}
    Position(int _x, int _y):x(_x),y(_y){}

    bool operator==( const Position &pos ) const { 
        return ( x == pos.x && y == pos.y );
    }
    bool operator!=( const Position &pos ) const {
        return ( x != pos.x || y != pos.y );
    }
    bool operator<( const Position &pos ) const {
        if( x == pos.x ) {
            return ( y < pos.y );
        }
        return ( x < pos.x );
    }

    friend std::ostream& operator<< ( std::ostream &o, const Position &pos ) {
        return o << "(" << pos.x << ", " << pos.y << ")";
    }

    Position getAdjacent( const Direction &direction, const int &len ) const;

    int x;
    int y;
};


#endif // POSITION_H

