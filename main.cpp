#include <iostream>
#include <fstream>
#include <sstream>
#include "extraFile.h"
#include <vector>
using namespace std;

void readStoreString(fstream& file, string& value) {
    int length = 0;
    file.read((char*)&length, 4);
    char* array = new char[length];
    file.read(array, length);
    value = array;
    delete[] array;
}


int main()
{

    fstream file;

    cout << "Which file(s) to open?\n";
    cout << "1. friendlyships.shp" << endl;
    cout << "2. enemyships.shp" << endl;
    cout << "3. Both files" << endl;
    int option;
    cin >> option;

    /* Load files here */
    if (option == 1) {
        file.open("friendlyships.shp", ios_base::in | ios_base::binary);
    } else if (option == 2) {
        file.open("enemyships.shp", ios_base::in | ios_base::binary);
    } else {
        //file.open(""); open both
    }

    vector<Ship> ships;
    int shipsCount = 0;
    file.read((char*)&shipsCount, 4);

    for (int i = 0; i < shipsCount; i++) {
        Ship ship;

        readStoreString(file, ship.name);
        readStoreString(file, ship.shipClass);

        file.read((char*)&ship.length, 2); //short
        file.read((char*)&ship., 4); //int
        file.read((char*)&ship, 4); //float

        for (int j = 0; j < shipsCount; j++) {

            Ship::Weapons weapons;
            readStoreString(file, weapons.name);
            file.read((char*)&weapons.whatever6, 4); //int
            file.read((char*)&weapons.whatever7, 4); //float

        }
        ships.push_back(ship);
    }


    cout << "1. Print all ships" << endl;
    cout << "2. Starship with the strongest weapon" << endl;
    cout << "3. Strongest starship overall" << endl;
    cout << "4. Weakest ship (ignoring unarmed)" << endl;
    cout << "5. Unarmed ships" << endl;

    cin >> option;

    /* Work your magic here */

    return 0;
}