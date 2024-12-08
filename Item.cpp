#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <vector>
#include "Item.h"
#include "Functions.h"

using namespace std;

vector<Weapon> Weapon::allWeapons;
vector<Armor> Armor::allArmors;

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
        weapon.price = stoi(lineArray[3]);
        weapon.type = 'w';
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


void Armor::setArmorsList(string filePath) {
    vector<Armor> readArmors;
    ifstream armorsFile(filePath);
    string line;

    while (getline(armorsFile, line)) {
        Armor armor;
        auto lineArray = Functions::explode(line, ';');
        armor.name = lineArray[0];
        armor.armorBonus = stoi(lineArray[1]);
        armor.price = stoi(lineArray[2]);
        armor.type = 'a';
        allArmors.push_back(armor);
    }
}

Armor Armor::getArmorByName(string name) {
    for(Armor armor : allArmors) {
        if (armor.name == name)
        {
            return armor;
        }
    }
    return Armor();
}

vector<Armor> Armor::getArmorsList() {
    return allArmors;
}