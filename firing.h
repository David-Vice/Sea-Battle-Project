/// firing.h
#pragma once
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#include "showdesks.h"

using namespace std;

void Fire(int** desk1, int** desk2);
bool PlayerWins(int** desk);
void RandomShot(int** desk1, int** desk2, bool Show2, bool rev);
void GiveNewPosPtr(int** desk, int& row, int& column);
void DelPrevPosPtr(int** desk, int& row, int& column);

void Fire(int** desk1, int** desk2) {
    int key = 0;
    int row = 4;
    int column = 4;
    GiveNewPosPtr(desk2, row, column);

    ShowDesks(desk1, desk2, false);
    while (true)
    {
        key = _getch();
        //cout << key;
        if (key == 80 && row != 9)
        {
            //"Down"
            DelPrevPosPtr(desk2, row, column);
            row++;
            GiveNewPosPtr(desk2, row, column);
            system("cls");
            ShowDesks(desk1, desk2, false);
        }
        else if (key == 72 && row != 0)
        {
            //"Up"
            DelPrevPosPtr(desk2, row, column);
            row--;
            GiveNewPosPtr(desk2, row, column);
            system("cls");
            ShowDesks(desk1, desk2, false);
        }
        else if (key == 75 && column != 0)
        {
            //"Left"
            DelPrevPosPtr(desk2, row, column);
            column--;
            GiveNewPosPtr(desk2, row, column);
            system("cls");
            ShowDesks(desk1, desk2, false);
        }
        else if (key == 77 && column != 9)
        {
            //"Right"
            DelPrevPosPtr(desk2, row, column);
            column++;
            GiveNewPosPtr(desk2, row, column);
            system("cls");
            ShowDesks(desk1, desk2, false);
        }
        else if (key == 113) {
            system("cls");
            cout << "Good bye!" << endl;
            exit(EXIT_SUCCESS);
        }
        else if (key == 13) {
            //"Fire"
            if (desk2[row][column] - 2 == 1) {
                desk2[row][column] = 15; //shot
                row = 4;
                column = 4;
                GiveNewPosPtr(desk2, row, column);
                if (PlayerWins(desk2)) {
                    system("cls");
                    break;
                }
                system("cls");
                ShowDesks(desk1, desk2, false);
            }
            else if (desk2[row][column] - 2 == 0) {
                desk2[row][column] = 14; //no ship
                system("cls");
                break;
            }
            else {
                cout << "You have already tried this point!" << endl;
                system("pause");
                system("cls");
                ShowDesks(desk1, desk2, false);
            }
        }
    }
}

void RandomShot(int** desk1, int** desk2, bool Show2, bool rev) {
    srand(time(NULL));
    if (rev)ShowDesks(desk2, desk1, Show2);
    else ShowDesks(desk1, desk2, Show2);
    while (true) {
        int coord = rand() % 100;
        int row = coord / 10;
        int column = coord % 10;
        if (desk1[row][column] == 1) {
            desk1[row][column] = 15; //shot
            Sleep(1000);///
            system("cls");
            if (rev) {
                if (PlayerWins(desk2)) {
                    system("cls");
                    break;
                }
                else ShowDesks(desk2, desk1, Show2);
            }
            else {
                if (PlayerWins(desk1)) {
                    system("cls");
                    break;
                }
                else ShowDesks(desk1, desk2, Show2);
            }
        }
        else if (desk1[row][column] == 0) {
            desk1[row][column] = 14; //no ship
            Sleep(1000);///
            system("cls");
            break;
        }
    }
}

void GiveNewPosPtr(int** desk, int& row, int& column) {
    desk[row][column] += 2;
}

void DelPrevPosPtr(int** desk, int& row, int& column) {
    desk[row][column] -= 2;
}

bool PlayerWins(int** desk) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (desk[i][j] == 1) return false;
            if (i == 9 && j == 9) return true;
        }
    }
}
