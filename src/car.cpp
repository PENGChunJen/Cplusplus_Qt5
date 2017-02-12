#include <iostream>
#include "car.h"

using namespace std;

Car::Car(const string& _owner, const string& _plate) {
    type = CAR;

    owner = _owner;
    plate = _plate;
}

bool Car::join( Object* objPtr ) { 
    if( objPtr->getType() == CAR ) {
        Crashed = true;
        return true;
    }
    return false;
}

void Car::printStatus() const {
    cout << "{ " << endl
        << "\towner: " << owner << "," << endl
        << "\tplate: " << plate << "," << endl
        << "\tCrashed: " << Crashed << endl
        << "}" << endl;
}
