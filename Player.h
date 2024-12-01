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
        int gold;
        list<Item> equipment;
        Weapon equipedWeapon;
        Armor equipedArmor;
    
    Player() {
        level = 1;
        health = 20;
        maxHealth = 20;
        armorRating = 10;
        xp = 0;
        gold = 0;
        equipedWeapon = Weapon::getWeaponByName("Piesci");
    }

    public:
    void printPlayerInfo();
    char getUserAction();
    void initiateFight();
    void checkForLevelUp();
    void rest();
    void attack(vector<Enemy>& fightingEnemies);
    bool escape(vector<Enemy>& fightingEnemies);
    void equipItem(Item item);
};
