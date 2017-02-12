#ifndef CAR_H 
#define CAR_H 

#include <string>

#include "object.h"

class Car : public Object {
public:
    Car(const std::string& _owner, const std::string& _plate);
    bool join( Object* objPtr );
    void printStatus() const; 

private:
    bool Crashed;
    std::string owner;
    std::string plate;
};

#endif // CAR_H 
