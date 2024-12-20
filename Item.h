#include <iostream>
#pragma once

using namespace std;

class Item {
    public:
        string name;
        int price;
        char type;
};

class Weapon : public Item{
    public:
        int minDamage;
        int maxDamage;

        static void setWeaponsList(string filePath); 
        static vector<Weapon> getWeaponsList();
        static Weapon getWeaponByName(string name);

    private:
        static vector<Weapon> allWeapons;
};

class Armor : public Item{
    public:
        int armorBonus;
        static void setArmorsList(string filePath); 
        static vector<Armor> getArmorsList();
        static Armor getArmorByName(string name);

    private:
        static vector<Armor> allArmors;

};