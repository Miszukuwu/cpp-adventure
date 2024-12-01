#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <vector>
#include "Item.h"
#include "Functions.h"

using namespace std;

vector<Weapon> Weapon::allWeapons;

void Weapon::setWeaponsList(string filePath) {
    vector<Weapon> readWeapons;
    ifstream weaponsFile(filePath);
    string line;

    while (getline(weaponsFile, line)) {
        Weapon weapon;
        auto lineArray = Functions::explode(line, ';');
        weapon.name = lineArray[0];
        weapon.minDamage = stoi(lineArray[1]);
        weapon.maxDamage = stoi(lineArray[2]);
        allWeapons.push_back(weapon);
    }
}

Weapon Weapon::getWeaponByName(string name) {
    for(Weapon weapon : allWeapons) {
        if (weapon.name == name)
        {
            return weapon;
        }
    }
    return Weapon();
}

vector<Weapon> Weapon::getWeaponsList() {
    return allWeapons;
}