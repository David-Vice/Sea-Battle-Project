/// array.h
#pragma once
#include <iostream>

using namespace std;

void InitArr(int** arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = new int[size] {};
    }
}

void GiveVals(int** arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr[i][j] = rand() % 2;
        }
    }
}

void ShowArr(int** arr, int size) {
    cout << "{" << endl;
    for (int i = 0; i < size; i++) {
        cout << "[ ";
        for (int j = 0; j < size; j++) {
            cout << arr[i][j];
            j == size - 1 ? cout << "" : cout << ",";
        }
        cout << " ]" << endl;
    }
    cout << "}" << endl;
}

void DelArr(int** arr, int size) {
    for (int i = 0; i < size; i++) { delete[] arr[i]; }
    delete[] arr;
}
