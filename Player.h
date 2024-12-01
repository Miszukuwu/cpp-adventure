#include <iostream>
#include <list>
#include <vector>
#include "Item.h"
#include "Enemy.h"
#pragma once

using namespace std;

class Player
{
    public:
        int level;
        int health;
        int maxHealth;
        int armorRating;
        int xp;
        list<Item> equipment;
        Weapon equipedWeapon;
        Armor equipedArmor;
    
    Player() {
        level = 1;
        health = 20;
        maxHealth = 20;
        armorRating = 10;
        xp = 0;
        for (Weapon weapon : Weapon::getWeaponsList())
        {
            if (weapon.name == "Piesci")
            {
                equipedWeapon = weapon;
            }
        }
    }

    public:
    void printPlayerInfo();
    char getUserAction();
    void initiateFight();
    void checkForLevelUp();
    void attack(vector<Enemy>& fightingEnemies);
    bool escape(vector<Enemy>& fightingEnemies);
};
