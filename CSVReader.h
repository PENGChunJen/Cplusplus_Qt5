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
            cerr << "Cannot open file:" << filename << endl ;
            return false;
        }

        string line;
        while( getline(inFile,line, '\n') ){

            vector<int> row;
        
            istringstream ss(line);
            string item;
            while( getline(ss, item, ',') ) {
                row.push_back( stoi( item ) );
            }

            data.push_back( row );
        }
        return true;
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
    vector< vector<int> > data;
};

#endif
