#ifndef POSITION_H
#define POSITION_H

struct Position {
    Position(){}
    Position(int _x, int _y):x(_x),y(_y){}
    int x;
    int y;

    bool operator==( const Position &a ) const{
        return ( x == a.x && y == a.y );
    }
};

#endif // POSITION_H

