#include "json.hpp"
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <map>
#include <set>
using namespace std;
using json = nlohmann::json;

class park{
public:
    park(){
        setCapacity(0, 0);
        setAvailable(0, 0);
        setTW97(0, 0);
        _isMRT = false;
    }
    park(string id, string name){
        setID(id);
        setName(name);
        setCapacity(0, 0);
        setAvailable(0, 0);
        setTW97(0, 0);
        _isMRT = false;
    }
    string getID(){ return _id; }
    void setID(string ID){
        _id = ID;
    }
    void setName(string name){
        _name = name;
    }
    void setCapacity(int car, int motor){
        _capacity[0] = car;
        _capacity[1] = motor;
    }
    void setAvailable(int car, int motor){
        _available[0] = car;
        _available[1] = motor;
    }
    void setTW97(double x, double y){
        _tw97x = x;
        _tw97y = y;
    }
    void print(ostream* out = &cout){
        *out << "ID: " << _id << ", Name: " << _name << endl;
        *out << "--- Capacity: " << _capacity[0] << ", " << _capacity[1] << endl;
        *out << "--- Available: " << _available[0] << ", " << _available[1] << endl;
        *out << "--- TW97: " << _tw97x << ", " << _tw97y << endl;
        *out << "MRT: " << (_isMRT ? "Yes" : "No") << endl;
    }
private:
    string _id;
    string _name;
    int _capacity[2]; //[0]: car, [1]: motor
    int _available[2]; //[0]: car, [1]: motor
    double _tw97x;
    double _tw97y;
    bool _isMRT;
};

int main(){
    json j;
    ifstream desc_file("../Data/TCMSV_alldesc");
    map<string,park*> id2parkptr;

    if(desc_file.is_open()){
        desc_file >> j;
        int total_parks = j["data"]["park"].size();
        cout << "Total # of parks: " << j["data"]["park"].size() << endl;

        for(int i=0;i<total_parks;i++){
            park* p = new park(j["data"]["park"][i]["id"], j["data"]["park"][i]["name"]);
            string t_car = j["data"]["park"][i]["totalcar"];
            string t_motor = j["data"]["park"][i]["totalmotor"];
            p->setCapacity(stoi(t_car), stoi(t_motor));
            string tx = j["data"]["park"][i]["tw97x"];
            string ty = j["data"]["park"][i]["tw97y"];
            p->setTW97(stod(tx), stod(ty));
            id2parkptr[p->getID()] = p;
        }
    }

    json j2;
    ifstream avai_file("../Data/TCMSV_allavailable");

    if(avai_file.is_open()){
        avai_file >> j2;

        for(int i=0;i<j2["data"]["park"].size();i++){
            string id = j2["data"]["park"][i]["id"];
            if(id2parkptr.find(id)!=id2parkptr.end()){
                string c_car = j2["data"]["park"][i]["availablecar"];
                string c_motor = j2["data"]["park"][i]["availablemotor"];
                id2parkptr[id]->setAvailable(stoi(c_car),stoi(c_motor));
            }
        }
    }

    ifstream mrt_park("../Data/臺北捷運轉乘停車場座標.csv");

    if (mrt_park.is_open()){
        string line;
        while ( getline (mrt_park,line) ){
            cout << line << '\n';
        }
        mrt_park.close();
    }


    ofstream output_file;
    output_file.open("output.txt");
    output_file.precision(9);
    for (map<string,park*>::iterator it=id2parkptr.begin(); it!=id2parkptr.end(); ++it){
        it->second->print(&output_file);
    }

    return 0;
}

