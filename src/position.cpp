#include <iostream>

#include "position.h"

std::ostream& operator << (std::ostream &o, const Position &p) {
    return o << "(" << p.x << ", " << p.y << ")";
}
