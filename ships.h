/// ships.h
#pragma once
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#include "showdesks.h"

using namespace std;

void PutShip(int** desk1, int** desk2, int shipsize);
void RandomPos(int** desk, int shipsize);
void GiveNewPosHor(int** desk, int& row, int& column, int shipsize);
void DelPrevPosHor(int** desk, int& row, int& column, int shipsize);
void GiveNewPosVer(int** desk, int& row, int& column, int shipsize);
void DelPrevPosVer(int** desk, int& row, int& column, int shipsize);
void Reverse(int** desk, int row, int column, int shipsize, int pos);
bool CheckPos(int** desk, int row, int column, int shipsize, int pos, bool manual);

void PutShip(int** desk1, int** desk2, int shipsize) {
    int pos = 1;
    int key = 0;
    int row = 0;
    int column = 0;
    GiveNewPosHor(desk1, row, column, shipsize);

    ShowDesks(desk1, desk2, false);
    while (true)
    {
        key = _getch();
        //cout << key;
        if (key == 80 && row != 9)
        {
            //"Down"
            if (pos == 1) {
                DelPrevPosHor(desk1, row, column, shipsize);
                row++;
                GiveNewPosHor(desk1, row, column, shipsize);
            }
            else if (pos == 2 && row <= 9 - shipsize) {
                DelPrevPosVer(desk1, row, column, shipsize);
                row++;
                GiveNewPosVer(desk1, row, column, shipsize);
            }
            system("cls");
            ShowDesks(desk1, desk2, false);
        }
        else if (key == 72 && row != 0)
        {
            //"Up"
            if (pos == 1) {
                DelPrevPosHor(desk1, row, column, shipsize);
                row--;
                GiveNewPosHor(desk1, row, column, shipsize);
            }
            else if (pos == 2) {
                DelPrevPosVer(desk1, row, column, shipsize);
                row--;
                GiveNewPosVer(desk1, row, column, shipsize);
            }
            system("cls");
            ShowDesks(desk1, desk2, false);
        }
        else if (key == 75 && column != 0)
        {
            //"Left"
            if (pos == 1) {
                DelPrevPosHor(desk1, row, column, shipsize);
                column--;
                GiveNewPosHor(desk1, row, column, shipsize);
            }
            else if (pos == 2) {
                DelPrevPosVer(desk1, row, column, shipsize);
                column--;
                GiveNewPosVer(desk1, row, column, shipsize);
            }
            system("cls");
            ShowDesks(desk1, desk2, false);
        }
        else if (key == 77 && column != 9)
        {
            //"Right"
            if (pos == 1 && column <= 9 - shipsize) {
                DelPrevPosHor(desk1, row, column, shipsize);
                column++;
                GiveNewPosHor(desk1, row, column, shipsize);
            }
            else if (pos == 2) {
                DelPrevPosVer(desk1, row, column, shipsize);
                column++;
                GiveNewPosVer(desk1, row, column, shipsize);
            }
            system("cls");
            ShowDesks(desk1, desk2, false);
        }
        else if (key == 114) {
            //"Reverse"
            if (pos == 1 && row <= 10 - shipsize) {
                Reverse(desk1, row, column, shipsize, pos);
                pos = 2;
            }
            else if (pos == 2 && column <= 10 - shipsize) {
                Reverse(desk1, row, column, shipsize, pos);
                pos = 1;
            }
            system("cls");
            ShowDesks(desk1, desk2, false);
        }
        else if (key == 113) {
            system("cls");
            cout << "Good bye!" << endl;
            exit(EXIT_SUCCESS);
        }
        else if (key == 13) {
            //"Save"
            bool OK = CheckPos(desk1, row, column, shipsize, pos, true);
            if (OK) {
                system("cls");
                break;
            }
            else {
                cout << "Choose the correct position for your ship!" << endl;
                system("pause");
                system("cls");
                ShowDesks(desk1, desk2, false);
            }
        }
    }
}

void RandomPos(int** desk, int shipsize) {
    srand(time(NULL));
    for (int coord = 10; coord < 100; coord += 4) {
        int row = coord / 10;
        int column = coord % 10;
        int pos = rand() % 2 + 1;
        bool OK = CheckPos(desk, row, column, shipsize, pos, false);
        if (OK) {
            if (pos == 1 && column <= 10 - shipsize) { GiveNewPosHor(desk, row, column, shipsize); break; }
            else if (pos == 2 && row <= 10 - shipsize) { GiveNewPosVer(desk, row, column, shipsize); break; }
        }
    }
}

void GiveNewPosHor(int** desk, int& row, int& column, int shipsize) {
    for (int i = 0; i < shipsize; i++) {
        desk[row][column + i]++;
    }
}

void DelPrevPosHor(int** desk, int& row, int& column, int shipsize) {
    for (int i = 0; i < shipsize; i++) {
        desk[row][column + i]--;
    }
}

void GiveNewPosVer(int** desk, int& row, int& column, int shipsize) {
    for (int i = 0; i < shipsize; i++) {
        desk[row + i][column]++;
    }
}

void DelPrevPosVer(int** desk, int& row, int& column, int shipsize) {
    for (int i = 0; i < shipsize; i++) {
        desk[row + i][column]--;
    }
}

void Reverse(int** desk, int row, int column, int shipsize, int pos) {
    if (pos == 1) {
        DelPrevPosHor(desk, row, column, shipsize);
        GiveNewPosVer(desk, row, column, shipsize);
    }
    else if (pos == 2) {
        DelPrevPosVer(desk, row, column, shipsize);
        GiveNewPosHor(desk, row, column, shipsize);
    }
}

bool CheckPos(int** desk, int row, int column, int shipsize, int pos, bool manual) {
    bool OK = true;
    for (int i = 0; i < shipsize; i++) {
        if (pos == 1) {
            if (i == 0) {
                if (column != 0) {
                    if (desk[row][column - 1] == 1) { OK = false; break; }
                    if (row != 0) {
                        if (desk[row - 1][column - 1] == 1) { OK = false; break; }
                    }
                    if (row != 9) {
                        if (desk[row + 1][column - 1] == 1) { OK = false; break; }
                    }
                }
            }

            if (desk[row][column + i] == 2 && manual) { OK = false; break; }
            if (desk[row][column + i] == 1 && !manual) { OK = false; break; }
            if (row != 0) {
                if (desk[row - 1][column + i] == 1) { OK = false; break; }
            }
            if (row != 9) {
                if (desk[row + 1][column + i] == 1) { OK = false; break; }
            }

            if (i == shipsize - 1) {
                if (column + shipsize - 1 != 9) {
                    if (desk[row][column + i + 1] == 1) { OK = false; break; }
                    if (row != 0) {
                        if (desk[row - 1][column + i + 1] == 1) { OK = false; break; }
                    }
                    if (row != 9) {
                        if (desk[row + 1][column + i + 1] == 1) { OK = false; break; }
                    }
                }
            }
        }
        else if (pos == 2) {
            if (i == 0) {
                if (row != 0) {
                    if (desk[row - 1][column] == 1) { OK = false; break; }
                    if (column != 0) {
                        if (desk[row - 1][column - 1] == 1) { OK = false; break; }
                    }
                    if (column != 9) {
                        if (desk[row - 1][column + 1] == 1) { OK = false; break; }
                    }
                }
            }
            if (desk[row + i][column] == 2 && manual) { OK = false; break; }
            if (desk[row + i][column] == 1 && !manual) { OK = false; break; }
            if (column != 0) {
                if (desk[row + i][column - 1] == 1) { OK = false; break; }
            }
            if (column != 9) {
                if (desk[row + i][column + 1] == 1) { OK = false; break; }
            }
            if (i == shipsize - 1) {
                if (row + shipsize - 1 != 9) {
                    if (desk[row + i + 1][column] == 1) { OK = false; break; }
                    if (column != 0) {
                        if (desk[row + i + 1][column - 1] == 1) { OK = false; break; }
                    }
                    if (column != 9) {
                        if (desk[row + i + 1][column + 1] == 1) { OK = false; break; }
                    }
                }
            }
        }
    }
    return OK;
}
