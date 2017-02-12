#ifndef PARK_H
#define PARK_H

#include <string>

#include "../util/util.h"
#include "object.h"
#include "car.h"


class Park : public Object {
public:
    Park( const std::string& _parkID, const std::string& _name,
          const int& _capacity, const int& _free, const bool& _isMRT ); 

    bool join( Object* objPtr );
    void printStatus() const;

private:
    std::string parkID;
    std::string name;
    int capacity;
    int free;
    bool isMRT;
};

#endif // PARK_H
