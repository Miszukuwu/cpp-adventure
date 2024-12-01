#include <iostream>
#include <list>
#include <vector>
#include "Item.h"
#include "Functions.h"
#pragma once

using namespace std;

class ReadEnemy {
    public:
        string enemyName;
        int level;
        int minHealth;
        int maxHealth;
        int armorRating;
        Weapon equippedWeapon;

        static void setEnemyList(string filePath);
        static vector<ReadEnemy> getEnemyList();

    private:
        static vector<ReadEnemy> allEnemies;
};