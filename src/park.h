#ifndef PARK_H
#define PARK_H

#include <string>
#include "object.h"
#include "../util/util.h"


class Park : public Object {
public:
    Park() {
        type = PARK;
    }

private:
    std::string parkId;
    std::string name;
    TWD97 pos;
    int capacity;
    int free;
    bool isMrt;
};

#endif // PARK_H
