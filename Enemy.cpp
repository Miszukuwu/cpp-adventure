#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Enemy.h"
#include "Functions.h"

using namespace std;

list<Enemy> Enemy::allEnemies;

void Enemy::setEnemyList(string filePath) {
    ifstream enemiesFile(filePath);
    string line;

    while (getline(enemiesFile, line)) {
        Enemy enemy;
        auto lineArray = Functions::explode(line, ';');
        enemy.enemyName = lineArray[0];
        enemy.level = stoi(lineArray[1]);
        enemy.health = stoi(lineArray[2]);
        enemy.mana = stoi(lineArray[3]);
        enemy.armorRating = stoi(lineArray[4]);
        allEnemies.push_front(enemy);
    }
}

list<Enemy> Enemy::getEnemyList() {
    return allEnemies;
}
