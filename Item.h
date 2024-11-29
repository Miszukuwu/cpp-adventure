#include <iostream>
#pragma once

using namespace std;

class Item {
    public:
        string name;
        int price;
        int weight;
};

class Weapon : public Item{
    public:
        int minDamage;
        int maxDamage;
};

class Consumable : public Item{
    public:
        int healthRestoreValue;
        int manaRestoreValue;
};

class Armor : public Item{
    public:
        int armorBonus;
};