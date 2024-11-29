#include <iostream>
#include <list>
#pragma once

using namespace std;

class Enemy {
    public:
        string enemyName;
        int level;
        int health;
        int mana;
        int armorRating;

        static void setEnemyList(string filePath);
        static list<Enemy> getEnemyList();

    private:
        static list<Enemy> allEnemies;
};
