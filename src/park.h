#ifndef PARK_H
#define PARK_H

#include "object.h"

class Park : public Object {

public:
    Park( const std::string& _id, const std::string& _name, 
          const int& _capacity, const int& _free, const bool& _isMRT );

    bool join( Object* objPtr );
    void printStatus() const;
    bool isFull() const { return (free < 1); }
    bool isSupplyStop() const { return isMRT; }
    
    std::string getId() { return id; }
    int getFree() { return free; }
private:
    std::string id;
    std::string name;
    int capacity;
    int free;
    bool isMRT;
};

#endif // PARK_H
