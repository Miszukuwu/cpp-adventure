#include <iostream>
#include <list>
#include <vector>
#include "Item.h"
#include "Functions.h"
#pragma once

using namespace std;

class Enemy {
    public:
        string enemyName;
        int level;
        int health;
        int armorRating;
        Weapon equippedWeapon;

        Enemy(string enemyName, int level, int minHealth, int maxHealth, int armorRating, Weapon weapon);

        void printEnemyInfo();
};