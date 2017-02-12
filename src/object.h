#ifndef OBJECT_H
#define OBJECT_H

#include <stdlib.h>

enum Type{
    EMPTY,
    WALL,
    PARK,
    CAR
};

class Object{

public:
    Object() { type = EMPTY; }
    Type getType(){ return type; }
    size_t getId(){ return id; }
    virtual bool join( Object* objPtr ){}
    virtual void printStatus() const {}

protected:
    Type type;
    size_t id;
};

#endif // OBJECT_H
