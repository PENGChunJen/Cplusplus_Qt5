#include <iostream>
#include <string>

#include "park.h"

using std::cout; using std::endl; using std::string;

Park::Park( const string& _parkID,  const string& _name, 
            const int& _capaciy, const int& _free, const bool& _isMRT ) {
    type = PARK;

    parkID = _parkID;
    name = _name;
    capacity = _capaciy;
    free = _free;
    isMRT = _isMRT;
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
