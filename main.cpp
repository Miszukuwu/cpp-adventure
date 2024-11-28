#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAPROWS = 15;
const int MAPCOLUMNS = 35;
char map[MAPROWS][MAPCOLUMNS];

void renderMap() {
    cout<<"Press ESC to exit"<<endl;
    cout<<"Use W S A D or arrow keys to move"<<endl;
    for (int i = 0; i < MAPROWS; i++)
    {
        for (int j = 0; j < MAPCOLUMNS; j++)
        {
            cout<<map[i][j];
        }
        cout<<endl;
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
}
// void playerMove(char action) {
//     if (action == 'w' || action == 38)
//     {
//         for (int i = 0; i < MAPROWS; i++)
//         {
//             for (int j = 0; j < MAPCOLUMNS; j++)
//             {
//                 if (i != 0 && i != MAPROWS-1 && j != 0 && j != MAPCOLUMNS-1)
//                 {
//                     map[i][j] = map[i+1][j];
//                 }
//             }        
//         }
//     }
//     if (action == 's' || action == 40)
//     {
//         for (int i = 0; i < MAPROWS; i++)
//         {
//             for (int j = 0; j < MAPCOLUMNS; j++)
//             {
//                 map[i][j] = map[i-1][j];
//             }        
//         }
//     }
// }

int main() {
    srand(time(0));

    for (int i = 0; i < MAPROWS; i++)
    {
        for (int j = 0; j < MAPCOLUMNS; j++)
        {
            if (i == 0 || i == MAPROWS-1)
            {
                map[i][j] = 196; // Left Right boundaries: '│'
            } else if(j == 0 || j == MAPCOLUMNS-1) {
                map[i][j] = 179; // Top Bottom boundaries: '─'
            } else {
                map[i][j] = ' ';
            }
        }        
    }

    for (int i = 0; i < MAPROWS; i++)
    {
        for (int j = 0; j < MAPCOLUMNS; j++)
        {
            if(map[i][j] == ' ') {
                if((rand() % 70 + 1) == 1) {
                    map[i][j] = 'X';
                }
            }
        }        
    }

    map[MAPROWS/2][MAPCOLUMNS/2] = 219; // place player in the middle
    
    char action;
    while(action != '\e') {
        system("cls");
        renderMap();

        action = getUserInput();
        // Check if player moves
        if (action == 'w' || action == 's' || action == 'a' || action == 'd' || action == 37 || action == 38 || action == 39 || action == 40)
        {
            playerMove(action);
        }
        
    }

    return 0;
}