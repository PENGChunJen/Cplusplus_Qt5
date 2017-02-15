#ifndef CSVREADER_H
#define CSVREADER_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class CSVReader {
public:
    CSVReader() {}
    CSVReader( char* filename ) { readFile(filename); }

    bool readFile( char* filename ) {
        ifstream inFile(filename);
        if ( !inFile.is_open() ) {
            cerr << "Cannot open file: " << filename << endl ;
            return false;
        }

        string line;
        while( getline(inFile,line, '\n') ){

            vector<string> row;

            istringstream ss(line);
            string item;
            while( getline(ss, item, ',') ) {
				if(item.c_str()[0] == '\"')
					row.push_back( item.substr(1,item.length()-2) );
                else
					row.push_back( item );
            }

            data.push_back( row );
        }
        return true;
    }
	
	vector<string> row(int i){
		return data.at(i);
	}

	vector<string> column(int j){
		vector<string> r;
		for(int i=0; i < data.size(); ++i){
				string s = data.at(i).at(j);
				r.push_back(s);
		}
		return r;
	}
	
	string getData(int i, int j){
		return data.at(i).at(j);
	}
	
	int colNum(){
		return data.size();
	}
	
    void print() {
        for( int i = 0; i < data.size(); ++i) {
            for( int j = 0; j < data[i].size(); ++j ) {
                cout << data.at(i).at(j) << ",";
            }
            cout << "\b \n";
        }
    }

private:
    vector< vector<string> > data;
};

#endif
