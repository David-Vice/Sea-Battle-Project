#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <algorithm>

#include "array.h"
#include "ships.h"
#include "firing.h"
#include "showdesks.h"

using namespace std;

int main(void) {
    while (true) {
        system("cls");
        int mode;
        cout << "1)Human-AI\n2)AI-AI\nChoose mode: ";
        cin >> mode;

        int size = 10;
        int** desk1 = new int* [size];
        int** desk2 = new int* [size];
        InitArr(desk1, size);
        InitArr(desk2, size);

        int ships[10] = { 1,1,1,1,2,2,2,3,3,4 };

        if (mode == 1) {
            system("cls");
            cout << "1)Spawn ships manually\n2)Spawn ships automatically\nChoose mode: ";
            cin >> mode;
            system("cls");
            if (mode == 1) {
                for (int i = 0; i < 10; i++) PutShip(desk1, desk2, ships[i]);
                random_shuffle(ships, ships + 10);
                for (int i = 0; i < 10; i++) { RandomPos(desk2, ships[i]); }
            }
            else {
                random_shuffle(ships, ships + 10);
                for (int i = 0; i < 10; i++) { RandomPos(desk1, ships[i]); }
                random_shuffle(ships, ships + 10);
                for (int i = 0; i < 10; i++) { RandomPos(desk2, ships[i]); }
            }
            while (true) {
                Fire(desk1, desk2);
                bool player1 = PlayerWins(desk2);
                if (player1) {
                    ShowDesks(desk1, desk2, true);
                    cout << endl << "\t\t\t\t\tPlayer1 wins!" << endl << endl;
                    break;
                }
                RandomShot(desk1, desk2, false, false);
                bool player2 = PlayerWins(desk1);
                if (player2) {
                    ShowDesks(desk1, desk2, true);
                    cout << endl << "\t\t\t\t\tPlayer2 wins!" << endl << endl;
                    break;
                }
            }
            system("pause");
        }
        else {
            system("cls");
            random_shuffle(ships, ships + 10);
            for (int i = 0; i < 10; i++) { RandomPos(desk1, ships[i]); }
            random_shuffle(ships, ships + 10);
            for (int i = 0; i < 10; i++) { RandomPos(desk2, ships[i]); }
            while (true) {
                RandomShot(desk2, desk1, true, true); // temp false
                bool player1 = PlayerWins(desk2);
                if (player1) {
                    ShowDesks(desk1, desk2, true);
                    cout << endl << "\t\t\t\t\tPlayer1 wins!" << endl << endl;
                    break;
                }
                RandomShot(desk1, desk2, true, false); // temp false
                bool player2 = PlayerWins(desk1);
                if (player2) {
                    ShowDesks(desk1, desk2, true);
                    cout << endl << "\t\t\t\t\tPlayer2 wins!" << endl << endl;
                    break;
                }
            }
            system("pause");
        }

        DelArr(desk1, size);
        DelArr(desk2, size);

        system("cls");
        cout << "Enter 'T' to play again or 'E' to exit" << endl;
        int key;
        key = _getch();
        if (key != 116) {
            cout << "Good bye!" << endl;
            break;
        }
    }
    return 0;
}
