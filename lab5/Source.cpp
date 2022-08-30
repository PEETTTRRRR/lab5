#include <iostream>
#include <stdio.h>

using namespace std;

void auto_switch(double*& a, double*& b) {
    double* memory = a;
    a = b;
    b = memory;
}


int main(void) {
    double** matrix;
    int row;
    int col;
    cout << "|enter row: ";
    cin >> row;
    cout << "|enter col: ";
    cin >> col;

    matrix = new double* [row];
    for (int i = 0; i < row; i++)
        matrix[i] = new double[col];
    srand(time(NULL));  // "srand" - every time new random
    for (int i = 0; i < row; i++)
        for (int b = 0; b < col; b++)
            matrix[i][b] = rand() % 100 + 1;

    cout << "|original: ";
    cout << "\n";
    for (int i = 0; i < row; i++) {
        for (int b = 0; b < col; b++)
            cout << matrix[i][b] << "\t"; // "\t" - tabulation
        cout << endl;
    }
    cout << endl;

    auto_switch(matrix[0], matrix[1]);  // swap the first two lines for example

    cout << "|after swap the first two lines for example: ";
    cout << "\n";
    for (int i = 0; i < row; i++) {
        for (int b = 0; b < col; b++)
            cout << matrix[i][b] << "\t"; // "\t" - tabulation
        cout << endl;
    }
    cout << endl;


    for (int r = 1; r < row; r++) {         //sorting
        if (matrix[r-1][2] > matrix[r][2]) {
            auto_switch(matrix[r-1], matrix[r]);
            r = r - 2;
        }
        if (r <= 0) r = 1;                  //sorting 1st line
        if (matrix[0][2] > matrix[1][2]) {
            auto_switch(matrix[0], matrix[1]);
            r = 1;

        }

    }

    cout << "|after sorting: ";
    cout << "\n";
    for (int i = 0; i < row; i++) {
        for (int b = 0; b < col; b++)
            cout << matrix[i][b] << "\t"; 
        cout << endl;
    }
    cout << endl;

}
