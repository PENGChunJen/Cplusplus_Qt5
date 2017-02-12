#include <iostream>

#include "park.h"

using namespace std;

Park::Park( const string& _parkID,  const string& _name, 
            const int& _capaciy, const int& _free, const bool& _isMRT ) {
    parkID = _parkID;
    name = _name;
    capacity = _capaciy;
    free = _free;
    isMRT = _isMRT;

    type = PARK;
}

bool Park::join( Object * objPtr ) {
    if( objPtr->getType() != CAR ) {
        return false;
    }

    if(free < 1) {
        return false;
    }
    free = free-1;
    return true;
}

void Park::printStatus() const {
    cout << "{ " << endl
        << "\tID: " << parkID << "," << endl
        << "\tname: " << name << "," << endl
        << "\tcapacity: " << capacity << "," << endl
        << "\tfree: " << free << "," << endl
        << "\tisMRT: " << isMRT << endl
        << "}" << endl;
}
