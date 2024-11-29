#include <iostream>
#include <list>
#include "Item.h"
#pragma once

using namespace std;

class Player
{
    public:
        int level;
        int health;
        int mana;
        int armorRating;
        list<Item> equipment;
        Weapon equipedWeapon;
        Armor equipedArmor;
    
    Player() {
        level = 1;
        health = 10;
        mana = 10;
        armorRating = 10;
    }

    public:
    void printPlayerInfo();
    void initiateFight();
};
