#ifndef CAR_H 
#define CAR_H 

#include <string>

#include "object.h"

class Car : public Object {
public:
    Car() {
        type = CAR;
    }
private:
    std::string name;
};

#endif // CAR_H 
