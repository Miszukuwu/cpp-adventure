#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "ReadEnemy.h"

using namespace std;

const int SCREEN_HEIGHT = 15;
const int SCREEN_WIDTH = 35;
char renderBuffer[SCREEN_HEIGHT][SCREEN_WIDTH];
const int MAP_WIDTH = 500, MAP_HEIGHT = 500;
char map[MAP_HEIGHT][MAP_WIDTH];

int playerX = MAP_WIDTH/2;
int playerY = MAP_HEIGHT/2;

void renderMap() {

    // Render tiles from map to renderBuffer
    for (int i = playerY-SCREEN_HEIGHT/2; i < playerY+SCREEN_HEIGHT/2; i++) {
        for (int j = playerX-SCREEN_WIDTH/2; j < playerX+SCREEN_WIDTH/2; j++){
            if (i < 0 || i >= MAP_WIDTH || j < 0 || j >= MAP_HEIGHT) {
                renderBuffer[i-playerY+SCREEN_HEIGHT/2][j-playerX+SCREEN_WIDTH/2] = ' ';
            } else {
                renderBuffer[i-playerY+SCREEN_HEIGHT/2][j-playerX+SCREEN_WIDTH/2] = map[i][j];
            }
        }
    }
    // Render Boundaries and set tiles to ' '
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            if (i == 0 || i == SCREEN_HEIGHT-1) {
                renderBuffer[i][j] = 196; // Left Right boundaries: '│'
            } else if(j == 0 || j == SCREEN_WIDTH-1) {
                renderBuffer[i][j] = 179; // Top Bottom boundaries: '─'
            }
        }
    }

    cout<<"Player X: "<<playerX<<endl;
    cout<<"Player Y: "<<playerY<<endl;
    cout<<"Press ESC to exit"<<endl;
    cout<<"Use W S A D or arrow keys to move"<<endl;
    for (int i = 0; i < SCREEN_HEIGHT; i++)
    {
        string line = "";
        for (int j = 0; j < SCREEN_WIDTH; j++)
        {
            line += renderBuffer[i][j];
        }
        cout<<line<<endl;
    }
}
char getUserInput() {
    while (true) {
        // Iterate through all possible key codes (0 to 255)
        for (int keyCode = 0; keyCode < 256; ++keyCode) {
            // Check if the key with keyCode is currently
            // pressed
            if (GetAsyncKeyState(keyCode) & 0x8000) {
                // Convert the key code to ASCII character
                return static_cast<char>(keyCode);
            }
        }

        // Add a small delay to avoid high CPU usage
        Sleep(50);
    }
    // char input;
    // cin>>input;
    // return input;
}
void playerMove(char action) {
    map[playerY][playerX] = ' ';
    switch (action)
    {
    case 'w':
    case 38:
        if (playerY-1 <= 0) {
            break;
        }
        playerY--;
        break;
    case 's':
    case 40:
        if (playerY+1 >= MAP_HEIGHT-1) {
            break;
        }
        playerY++;
        break;
    case 'a':
    case 37:
        if (playerX-1 <= 0) {
            break;
        }
        playerX--;
        break;
    case 'd':
    case 39:
        if (playerX+1 >= MAP_WIDTH) {
            break;
        }
        playerX++;
        break;
    default:
        break;
    }
    map[playerY][playerX] = 219;
}

void initMap(){
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            int randomTile = (rand() % 70 + 1);
            if (i==0 || i==MAP_HEIGHT-1 || j==0 || j==MAP_WIDTH-1) {
                map[i][j] = 'X';
                continue;
            }
            if (randomTile == 1) {
                map[i][j] = 'O';
                continue;
            }
            map[i][j] = ' ';
        }
    }
    map[playerY][playerX] = 219;
}

int main() {
    Weapon::setWeaponsList("weapons.txt");
    ReadEnemy::setEnemyList("enemies.txt");

    srand(time(0));
    initMap();

    Player player;

    char action;
    while(action != '\e') {
        system("cls");
        renderMap();

        action = tolower(getUserInput());
        // Check if player moves
        if (action == 'w' || action == 's' || action == 'a' || action == 'd' || action == 37 || action == 38 || action == 39 || action == 40)
        {
            playerMove(action);
            Sleep(10);
        }
        if  (action == 'F') {
            player.initiateFight();
        }
    }

    return 0;
}