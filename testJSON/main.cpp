#include "../lib/json.hpp"
#include "../lib/tinyxml2.h"
#include "../util/CSVReader.h"
#include "../src/map.h"

#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <map>
#include <set>
using namespace std;
using json = nlohmann::json;

int main(){
    Map mymap;
    map<string,Park> id2parkptr;

    json j;
    ifstream desc_file("../data/TCMSV_alldesc");
    if(desc_file.is_open()){
        desc_file >> j;
        int total_parks = j["data"]["park"].size();
        cout << "Total # of parks: " << j["data"]["park"].size() << endl;

        for(int i=0;i<total_parks;i++){
            string id = j["data"]["park"][i]["id"];
            string name = j["data"]["park"][i]["name"];
            string t_car = j["data"]["park"][i]["totalcar"];
            string tx = j["data"]["park"][i]["tw97x"];
            string ty = j["data"]["park"][i]["tw97y"];
            Park p = {id, name, {stod(tx) ,stod(ty)}, stoi(t_car),0,false};
            id2parkptr[id] = p;
        }
    }

    json j2;
    ifstream avai_file("../data/TCMSV_allavailable");
    if(avai_file.is_open()){
        avai_file >> j2;

        for(int i=0;i<j2["data"]["park"].size();i++){
            string id = j2["data"]["park"][i]["id"];
            if(id2parkptr.find(id)!=id2parkptr.end()){
                string c_car = j2["data"]["park"][i]["availablecar"];
                id2parkptr[id].capacity = stoi(c_car);
            }
        }
    }

    CSVReader mrt_park;
    mrt_park.readFile("../data/臺北捷運轉乘停車場座標.csv");
    //mrt_park.print();

    for(auto it = id2parkptr.begin(); it != id2parkptr.end(); it++){
        mymap.addPark(it->second);
    }

    tinyxml2::XMLDocument doc;
    doc.LoadFile("../data/TCMSV_roadquery.xml");
    //printf( "%s\n", name );


    ofstream output_file;
    output_file.open("output.txt");
    output_file.precision(9);
    //mymap.printStatus( &output_file );

    output_file << doc.FirstChildElement("DATA")->FirstChildElement("ROAD")->FirstChildElement("roadSegName")->GetText();


    return 0;
}

