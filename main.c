#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N 10

int main()
{
    char strmap[N][255] = {0};
    int X = 1, Y = 1;
    char key;
    int oX, oY;

    int aX1 = 5, aY1 = 2;
    int aX2 = 7, aY2 = 4;
    int aX3 = 3, aY3 = 6;

    int wX = 8, wY = 8;

    do {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            if (j == 0 || i == 0 || j == N - 1 || i == N - 1)
                strmap[i][j] = '#';
            else
                strmap[i][j] = ' ';
    
    strmap[Y][X] = '@';

    strmap[aY1][aX1] = 'X';
    strmap[aY2][aX2] = 'X';
    strmap[aY3][aX3] = 'X';

    strmap[wY][wX] = 'W';

    system("cls");

    for (int i = 0; i < N; i++)
        printf("%s\n", strmap[i]);
    }
    
    key = getch();

    oX = X;
    oY = Y;

    if (key == 'w') Y--;
    if (key == 's') Y++;
    if (key == 'a') X--;
    if (key == 'd') X++;

    if (strmap[Y][X] == '#')
    {
        X = oX;
        Y = oY;
    }
    else if ((X == aX1) && (Y == aY1) || (X == aX2) && (Y == aY2) || (X == aX3) && (Y == aY3))
    {
        printf("Game over!");
        getch();
        break;
    }
    else if ((X == wX) && (Y == wY))
    {
        printf("You win!");
        getch();
        break;
    }

    }

    while (key != 'e');
    
    return 0;
}