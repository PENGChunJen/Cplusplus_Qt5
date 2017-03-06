#ifndef DATA_H
#define DATA_H

#include <map>

class Data{
public:
    Data();
    ~Data();

    void printStatus() const;

    void loadAllParks( const std::string& filename );
    void loadAvailableParks( const std::string& filename );
    void loadMRTParks( const std::string& filename );

    std::map< std::string, std::map< std::string, std::string > > parks;
};

#endif // DATA_H

