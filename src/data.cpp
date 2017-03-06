#include "CSVReader.h"
#include "../lib/json.hpp"
#include "../lib/tinyxml2.h"

#include "data.h"

using json = nlohmann::json;
using std::cerr; using std::cout; using std::endl; 
using std::map; using std::string;


Data::Data() {
    loadAllParks( "../data/TCMSV_alldesc" );
    loadAvailableParks( "../data/TCMSV_allavailable" );
    loadMRTParks( "../data/taipei_metro_park_position.csv" );
    printStatus();
}

Data::~Data() {
    parks.clear();
}

void Data::printStatus() const {

    for( auto const &item1 : parks ) {
        auto const &id = item1.first;
        auto const &park = item1.second;

        for( auto const &item2 : park )  {
            auto const &key = item2.first;
            auto const &value = item2.second;

            cout << key << ":" << value << ", ";
        }

        cout << "\n";
    }
}

void Data::loadAllParks( const string& filename ) {

    json allData;
    ifstream file(filename);

    /* Load JSON file into allData */
    if( !file.is_open() ) {
        cerr << "Cannot open file " << filename << endl;
    }
    else {
        file >> allData;
        file.close();
    }

    /* Save allData as map<string, string> in parks */
    int parkNum = allData["data"]["park"].size();
    for( int i = 0; i < parkNum; ++i ) {

        map<string, string> park;

        park["id"] = allData["data"]["park"][i]["id"];
        park["name"] = allData["data"]["park"][i]["name"];
        park["capacity"] = allData["data"]["park"][i]["totalcar"];
        park["available"] = allData["data"]["park"][i]["totalcar"];
        park["tw97x"] = allData["data"]["park"][i]["tw97x"];
        park["tw97y"] = allData["data"]["park"][i]["tw97y"];
        park["isMRT"] = "false";

        parks[ park["id"] ] = park;

    }
}

void Data::loadAvailableParks( const string& filename ) {

    json availableData;
    ifstream file(filename);

    /* Load JSON file into availableData */
    if( !file.is_open() ) {
        cerr << "Cannot open file " << filename << endl;
    }
    else {
        file >> availableData;
        file.close();
    }

    /* add available car number into parks */
    int parkNum = availableData["data"]["park"].size();
    for( int i = 0; i < parkNum; ++i ) {

        string id = availableData["data"]["park"][i]["id"];
        string available = availableData["data"]["park"][i]["availablecar"];

        auto it = parks.find( id );
        if( it != parks.end() ) {
            it->second["available"] = available;
        }
        else {
            cout << "Cannot find park with id: " << id << endl;
        }
    }

}

void Data::loadMRTParks( const string& filename ) {
    
    /* Use our CSVReader to read csv file */
    CSVReader csvReader( filename );

    for( int i = 1; i < csvReader.size(); ++i ) {
        string id = csvReader.at(i,0);
        string name = csvReader.at(i,1);
        string longitude = csvReader.at(i,2);
        string latitude = csvReader.at(i,3);
        
        auto it = parks.find( id );
        if( it != parks.end() ) {
            it->second["isMRT"] = "true";
        }
        else {
            cout << "MRT: Cannot find park with id: " << id << endl;
        }
    }

}

