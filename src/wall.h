#ifndef WALL_H
#define WALL_H

#include "object.h"

class Wall : public Object
{
public:
    Wall() {
        type = WALL;
    }
    virtual bool join( Object* objPtr ){ return false; }
    virtual void printStatus() const {}
};

#endif // WALL_H
