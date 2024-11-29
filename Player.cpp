#include <iostream>
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "Item.h"

using namespace std;

void Player::printPlayerInfo() {
    int rowLength = 30;
    cout<<"------====== Gracz ======------"<<endl;
    cout<<level<<" poziom";
    for (int i = 0; i < rowLength - (to_string(level) + " poziom" + to_string(health) + "zycie").length(); i++)
    {
        cout<<" ";
    }
    cout<<health<<" zycie"<<endl;

    cout<<armorRating<<" pancerz";
    for (int i = 0; i < rowLength - (to_string(armorRating) + " pancerz" + to_string(mana) + "mana").length(); i++)
    {
        cout<<" ";
    }
    cout<<mana<<" mana"<<endl;

    string equipedWeaponString = "Bron: " + ((equipedWeapon.name == "") ? "Piesci" : equipedWeapon.name);
    cout<<equipedWeaponString;

    string equipedArmorString = "Zbroja: " + ((equipedArmor.name == "") ? "Brak" : equipedArmor.name);
    for (int i = 0; i <= rowLength - (equipedWeaponString + equipedArmorString).length(); i++)
    {
        cout<<" ";
    }
    cout<<equipedArmorString<<endl;
}

void Player::initiateFight() {
    string choice;
    cout<<"Zaczela sie walka"<<endl;
    while (true)
    {
        printPlayerInfo();
        for(Enemy enemy : Enemy::getEnemyList()) {
            cout<<enemy.enemyName;
        }
        cin>>choice;
    }
}