// Copyright [2017] <MaoMao>

#include <stdio.h>

int matrix_chain_x(int* p, const int n, int** m, int** s)
{
    // Initial data
    for (int i = 0; i < n; i++)
        m[i][i] = 0;

    // m[i][j] is best maltipy result of matrix-chain i to j
    // s[i][j] is devide position of best maltipy result
    // l = j - i, from 1 to n-1
    for (int l = 1; l < n; l++)
    {
        for (int i = 0; i < n-l; i++)
        {
            int j = i + l;
            m[i][j] = -1;
            // Check all possible result of matrix-chain i to j, and find the max
            for (int k = i; k < j; k++)
            {
                int tmp = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (tmp < m[i][j] || m[i][j] == -1)
                {
                    m[i][j] = tmp;
                    s[i][j] = k;
                }
            }
        }
    }
    return m[0][n-1];
}

void matrix_chain_print(int** s, int i, int j)
{
    if (i == j)
        printf("A%d", i+1);
    else
    {
        printf("(");
        matrix_chain_print(s, i, s[i][j]);
        printf("*");
        matrix_chain_print(s, s[i][j]+1, j);
        printf(")");
    }
}
