#ifndef OBJECT_H
#define OBJECT_H

struct Position {
    int x;
    int y;
};

struct TWD97 {
    double x;
    double y;
};

enum Attribute{
    WALL,
    AGENT,
    PARK,
};

class Object{

public:
    Attribute getAttribute(){return attribute;}

protected:
    Attribute attribute;
};

#endif // OBJECT_H
