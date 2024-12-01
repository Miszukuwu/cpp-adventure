#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Functions.h"
#include "ReadEnemy.h"

using namespace std;

vector<ReadEnemy> ReadEnemy::allEnemies;

void ReadEnemy::setEnemyList(string filePath) {
    ifstream enemiesFile(filePath);
    string line;

    while (getline(enemiesFile, line)) {
        ReadEnemy enemy;
        auto lineArray = Functions::explode(line, ';');
        enemy.enemyName = lineArray[0];
        enemy.level = stoi(lineArray[1]);
        enemy.minHealth = stoi(lineArray[2]);
        enemy.maxHealth = stoi(lineArray[3]);
        enemy.armorRating = stoi(lineArray[4]);
        enemy.equippedWeapon = Weapon::getWeaponByName(lineArray[5]);
        
        allEnemies.push_back(enemy);
    }
}

vector<ReadEnemy> ReadEnemy::getEnemyList() {
    return allEnemies;
}