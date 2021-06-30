#include <iostream>

int main() {
    int valueBoard[8][8];
    valueBoard[0][0] = 120;
    valueBoard[0][1] = -20;
    valueBoard[0][2] = 20;
    valueBoard[0][3] = 5;
    valueBoard[1][1] = -40;
    valueBoard[1][2] = -5;
    valueBoard[1][3] = -5;
    valueBoard[2][2] = 15;
    valueBoard[2][3] = 3;
    valueBoard[3][3] = 3;
    for (int i = 1; i <= 3; i++)
        for (int j = 0; j < i; j++)
            valueBoard[i][j] = valueBoard[j][i];
    for (int i = 0; i < 4; i++)
        for (int j = 4; j < 8; j++)
            valueBoard[i][j] = valueBoard[i][7-j];
    for (int i = 4; i < 8; i++)
        for (int j = 4; j < 8; j++)
            valueBoard[i][j] = valueBoard[7-i][7-j];
    for (int i = 4; i < 8; i++)
        for (int j = 0; j < 4; j++)
            valueBoard[i][j] = valueBoard[i][7-j];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i != 7 || j != 7)
                std::cout << valueBoard[i][j]+5 << ", ";
            else
                std::cout << valueBoard[i][j]+5;
        }
        std::cout << "\n";
    }
}