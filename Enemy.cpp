#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "Functions.h"
#include "Enemy.h"

using namespace std;

Enemy::Enemy(string enemyName, int level, int minHealth, int maxHealth, int armorRating, Weapon equippedWeapon) {
    this->enemyName = enemyName;
    this->level = level;
    this->health = Functions::randomInt(minHealth, maxHealth);
    this->armorRating = armorRating;
    this->equippedWeapon = equippedWeapon;
}

void Enemy::printEnemyInfo() {
    int rowLength = ("------- " + enemyName + " -------").length();
    cout<<"------- "<<enemyName<<" -------"<<endl;
    cout<<health<<" zycie";
    for (int i = 0; i < rowLength - (to_string(health) + " zycie" + to_string(armorRating) + " pancerz").length(); i++)
    {
        cout<<" ";
    }
    cout<<armorRating<<" pancerz"<<endl<<endl;

}