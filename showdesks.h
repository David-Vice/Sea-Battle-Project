/// showdesks.h
#pragma once
#include <iostream>

using namespace std;

void ShowDesks(int** desk1, int** desk2, bool Show2) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int r = 1; r <= 22; r++) {
        for (int c = 1; c <= 45; c++) {
            ////// main part
            if (c % 2 != 0) {
                ////// numbers for sides
                if (c == 1 || c == 45) {
                    if ((r - 1) % 2 == 0 && r != 1) {
                        if ((r - 1) / 2 < 10) cout << (r - 1) / 2 << " ";
                        else cout << 10;
                    }
                    else cout << "  ";
                }
                ////// long line
                else if (c == 23) {
                    if (r == 11) {
                        for (int i = 0; i <= 14; i++) cout << " ";
                        cout << "SEA";
                        for (int i = 0; i <= 15; i++) cout << " ";
                    }
                    else if (r == 12) {
                        for (int i = 0; i <= 13; i++) cout << " ";
                        cout << "BATTLE";
                        for (int i = 0; i <= 13; i++) cout << " ";
                    }
                    else {
                        for (int i = 1; i <= 34; i++) {
                            if (r == 2 || r == 22) cout << char(205);
                            else cout << " ";
                        }
                    }
                }
                //////
                else if (r % 2 != 0) {
                    ////// letters
                    if (r == 1) {
                        if (c <= 22) cout << char((c - 1) / 2 + 64) << " ";
                        else cout << char((c - 1) / 2 + 53) << " ";
                    }
                    ////// connector
                    else {
                        if (c <= 22) {
                            int row = (r - 1) / 2 - 1;
                            int column = (c - 1) / 2 - 1;
                            if (desk1[row][column] == 1) {
                                cout << char(219) << char(219);
                            }
                            else if (desk1[row][column] == 2 || desk1[row][column] == 3 || desk1[row][column] == 16 || desk1[row][column] == 17)
                            {
                                SetConsoleTextAttribute(hConsole, 12);
                                cout << char(219) << char(219);
                                SetConsoleTextAttribute(hConsole, 15);
                            }
                            else if (desk1[row][column] == 14) {
                                SetConsoleTextAttribute(hConsole, 9);
                                cout << char(62) << char(60);
                                SetConsoleTextAttribute(hConsole, 15);
                            }
                            else if (desk1[row][column] == 15) {
                                SetConsoleTextAttribute(hConsole, 2);
                                cout << char(219) << char(219);
                                SetConsoleTextAttribute(hConsole, 15);
                            }
                            else cout << "  ";
                        }
                        else {
                            int row = (r - 1) / 2 - 1;
                            int column = (c - 23) / 2 - 1;
                            if (desk2[row][column] == 1 && Show2) { /// show comp
                                cout << char(219) << char(219);
                            }
                            else if ((desk2[row][column] == 2 || desk2[row][column] == 3 || desk2[row][column] == 16 || desk2[row][column] == 17))
                            {
                                SetConsoleTextAttribute(hConsole, 12);
                                cout << char(219) << char(219);
                                SetConsoleTextAttribute(hConsole, 15);
                            }
                            else if (desk2[row][column] == 14) {
                                SetConsoleTextAttribute(hConsole, 9);
                                cout << char(62) << char(60);
                                SetConsoleTextAttribute(hConsole, 15);
                            }
                            else if (desk2[row][column] == 15) {
                                SetConsoleTextAttribute(hConsole, 2);
                                cout << char(219) << char(219);
                                SetConsoleTextAttribute(hConsole, 15);
                            }
                            else cout << "  ";
                        }
                    }
                }
                else cout << char(205) << char(205);
            }

            ////// additional part
            else if (c % 2 == 0) {
                if (r == 2) {
                    if (c == 2) cout << char(201);
                    else if (c == 44) cout << char(187);
                    else cout << char(203);
                }
                else if (r == 22) {
                    if (c == 2) cout << char(200);
                    else if (c == 44) cout << char(188);
                    else cout << char(202);
                }
                else if (r % 2 != 0) {
                    if (r == 1) cout << " ";
                    else cout << char(186);
                }
                else if (r % 2 == 0) {
                    if (c == 2 || c == 24) cout << char(204);
                    else if (c == 22 || c == 44) cout << char(185);
                    else cout << char(206);
                }
            }
        }
        cout << endl;
    }
    if (!Show2) {
        cout << "Arrows - to change the position or to aim" << endl;
        cout << "Enter - to fix the position or to fire a shot" << endl;
        cout << "R - to change the direction of the ship" << endl;
        cout << "Q - to quit" << endl;
    }
    cout << endl;
    SetConsoleTextAttribute(hConsole, 12); cout << char(219) << char(219); SetConsoleTextAttribute(hConsole, 15); cout << "-used to aim or shows wrong position for ship     ";
    cout << char(219) << char(219) << "-your ship     ";
    SetConsoleTextAttribute(hConsole, 2); cout << char(219) << char(219); SetConsoleTextAttribute(hConsole, 15); cout << "-hit     ";
    SetConsoleTextAttribute(hConsole, 9); cout << char(62) << char(60); SetConsoleTextAttribute(hConsole, 15); cout << "-miss\n";
}
