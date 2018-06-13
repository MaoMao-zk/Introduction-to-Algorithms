// Copyright [2017] <MaoMao>

#include <string.h>
#include <stdio.h>

char* longest_common_subsequence(char* X, char* Y)
{
    int lenX = strlen(X);
    int lenY = strlen(Y);
    char* Z = new char[(lenX < lenY)?lenX+1:lenY+1];
    char** arrayDirect = new char*[lenX];
    for (int i = 0; i < lenX; i++)
        arrayDirect[i] = new char[lenY];
    int** arrayCount = new int*[lenX+1];
    for (int i = 0; i <= lenX; i++)
        arrayCount[i] = new int[lenY+1];

    for (int i = 0; i < lenX; i++)
        arrayCount[i][0] = 0;
    for (int i = 0; i < lenY; i++)
        arrayCount[0][i] = 0;

    for (int i = 1; i <= lenX; i++)
    {
        for (int j = 1; j <= lenY; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                arrayCount[i][j] = arrayCount[i - 1][j - 1] + 1;
                arrayDirect[i - 1][j - 1] = '=';
            }
            else if (arrayCount[i][j - 1] > arrayCount[i - 1][j])
            {
                arrayCount[i][j] = arrayCount[i][j - 1];
                arrayDirect[i - 1][j - 1] = '>';
            }
            else
            {
                arrayCount[i][j] = arrayCount[i - 1][j];
                arrayDirect[i - 1][j - 1] = '<';
            }
        }
    }

    int i = lenX - 1;
    int j = lenY - 1;
    while (i >= 0 && j >= 0)
    {
        if (arrayDirect[i][j] == '=')
        {
            Z[arrayCount[i+1][j+1]-1] = X[i];
            i--;
            j--;
        }
        else if (arrayDirect[i][j] == '>')
            j--;
        else
            i--;
    }
    Z[arrayCount[lenX][lenY]] = '\0';

    for (i = 0; i <= lenX; i++)
    {
        for (j = 0; j <= lenY; j++)
        {
            printf("%d ", arrayCount[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < lenX; i++)
    {
        for (j = 0; j < lenY; j++)
        {
            printf("%c ", arrayDirect[i][j]);
        }
        printf("\n");
    }

    return Z;
}
