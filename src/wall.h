#ifndef WALL_H
#define WALL_H

#include "object.h"

class Wall : public Object
{
public:
    Wall() {
        type = WALL;
    }
};
#endif // WALL_H
