#include <iostream>
#include <string>
#include "Functions.h"
#include "Player.h"
#include "Enemy.h"
#include "ReadEnemy.h"
#include "Item.h"

using namespace std;

void Player::printPlayerInfo() {
    string playerName = "-----===== Gracz =====-----";
    int rowLength = playerName.length();
    cout<<playerName<<endl;
    cout<<level<<" poziom";
    for (int i = 0; i < rowLength - (to_string(level) + " poziom" + to_string(health) + " zycie").length(); i++)
    {
        cout<<" ";
    }
    cout<<health<<" zycie"<<endl;

    string equipedWeaponString = "Bron: " + ((equipedWeapon.name == "") ? "Piesci" : equipedWeapon.name);
    cout<<equipedWeaponString;

    string equipedArmorString = "Zbroja: " + ((equipedArmor.name == "") ? "Brak" : equipedArmor.name);
    for (int i = 0; i < rowLength - (equipedWeaponString + equipedArmorString).length(); i++)
    {
        cout<<" ";
    }
    cout<<equipedArmorString<<endl<<endl;
}

char Player::getUserAction() {
    char choice;
    cout<<"Co robisz: "<<endl;
    cout<<"1. Atak"<<endl;
    cout<<"2. Ucieczka"<<endl;
    cin>>choice;
    return choice;
}

void Player::attack(vector<Enemy>& fightingEnemies) {
    system("cls");
    int choice;
    cout<<"Kogo chcesz zaatakowac: "<<endl;
    for (int i = 0; i < fightingEnemies.size(); i++)
    {
        cout<<i+1<<". "<<fightingEnemies[i].enemyName<<endl;
    }
    cin>>choice;
    choice--;

    int damage = Functions::randomInt(equipedWeapon.minDamage, equipedWeapon.maxDamage);
    fightingEnemies[choice].health -= damage;
    if (fightingEnemies[choice].health <= 0)
    {
        xp += fightingEnemies[choice].level * 10;
        cout<<"Pokonales "<<fightingEnemies[choice].enemyName<<". Dostales "<<fightingEnemies[choice].level * 10<<" doswiadczenia"<<endl;
        checkForLevelUp();
        fightingEnemies.erase(fightingEnemies.begin() + choice);
    } else {
        cout<<"Zaatakowales "<<fightingEnemies[choice].enemyName<<" zadajac "<<damage<<" obrazen"<<endl;
    }
    system("pause");
    system("cls");
}

bool Player::escape(vector<Enemy>& fightingEnemies) {
    if (fightingEnemies.size() == 1)
    {
        if (Functions::randomInt(1,4) <= 3)
        {
            return true;
        }
    } else if(fightingEnemies.size() == 2) {
        if (Functions::randomInt(1,2) == 1)
        {
            return true;
        }
    } else {
        if (Functions::randomInt(1,4) == 1)
        {
            return true;
        }
    }
    return false;
}

void Player::initiateFight() {
    system("cls");
    vector<ReadEnemy> possibleEnemies;
    vector<Enemy> fightingEnemies;
    bool correctAction = true, haveEscaped = false;

    for (const ReadEnemy& enemy : ReadEnemy::getEnemyList()) {
        if (enemy.level == level) {
            possibleEnemies.push_back(enemy);
        }
    }

    for (int i = 0; i < Functions::randomInt(1,3); i++) {
        ReadEnemy randomEnemy = possibleEnemies.at(Functions::randomInt(0, possibleEnemies.size()-1));
        fightingEnemies.push_back(Enemy(randomEnemy.enemyName, randomEnemy.level, randomEnemy.minHealth, randomEnemy.maxHealth, randomEnemy.armorRating, randomEnemy.equippedWeapon));
    }

    cout << "Zostales zaatakowany !" << endl;

    while (!fightingEnemies.empty() && !haveEscaped) {
        printPlayerInfo();
        for (Enemy& enemy : fightingEnemies) {
            enemy.printEnemyInfo();
        }

        do {
            char choice = getUserAction();
            switch (choice) {
                case '1':
                    attack(fightingEnemies);
                    correctAction = true;
                    break;
                case '2':
                    haveEscaped = escape(fightingEnemies);
                    correctAction = true;
                    break;
                default:
                    cout << "Nie ma takiej opcji" << endl;
                    correctAction = false;
                    break;
            }
        } while(!correctAction);

        if (!haveEscaped)
        {
            for (Enemy enemy : fightingEnemies) {
                int damage = Functions::randomInt(enemy.equippedWeapon.minDamage, enemy.equippedWeapon.maxDamage);
                health -= damage;
                cout<<enemy.enemyName<<" zaatakowal cie zadajac "<<damage<<endl;
            }
            if (!fightingEnemies.empty())
            {
                system("pause");
            }
        }
        
        system("cls");
    }
    if (haveEscaped)
    {
        cout<<"Udalo ci sie uciec"<<endl;
    } else {
        cout<<"Wygrales walke !"<<endl;
    }
    system("pause");
}

void Player::checkForLevelUp() {
    int xpToNextLevel = (level + 1) * 25;
    if (xpToNextLevel <= xp)
    {
        xp -= xpToNextLevel;
        level++;
        maxHealth += level * 3;
        cout<<"Zdobyles kolejny poziom ! Masz teraz "<<level<<" poziom"<<endl;
        health = maxHealth;
    }
}