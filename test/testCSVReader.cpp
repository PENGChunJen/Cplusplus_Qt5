#include <iostream>
#include "../src/CSVReader.h"

using namespace std;

int main (int argc, char *argv[]) {
    if ( argc != 2 ) {
        cout << "\n\tUsage ./testCSVReader <filename>\n\n";
        return -1;
    }

    char *filename = argv[1];

    CSVReader csvReader;
    csvReader.readFile(filename);

    //CSVReader csvReader(filename);

    csvReader.print();
}
