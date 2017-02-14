#ifndef OBJECT_H
#define OBJECT_H

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
    virtual bool join( Object* objPtr ){}
    virtual void printStatus() const {}

protected:
    Type type;
};

#endif // OBJECT_H
