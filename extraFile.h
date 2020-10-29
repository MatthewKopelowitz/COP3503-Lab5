#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#pragma once

struct Ship {

    string name;
    string shipClass;
    short length = 0;
    int shieldCapacity;
    float maxWarpSpeed;

    struct Weapons{

        string name;
        int whatever;
        float whatever2;
    };

    vector<Weapons> weapons;

};

