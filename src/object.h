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
    Type getType() const { return type; }
    unsigned int getID() const { return id;}
    virtual bool join( Object* objPtr ){ return false; }
    virtual void printStatus() const {}

protected:
    Type type;
    unsigned int id = ID_GENERATOR++;

    static unsigned int ID_GENERATOR;
};

#endif // OBJECT_H
