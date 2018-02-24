// Copyright [2017] <MaoMao>

#include "MatrixChainX.h"
#include "Utils.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

extern int** new_2v_array(int n);
extern void delete_2v_array(int** array, int n);

extern int matrix_chain_x(int* p, int n, int** m, int** s);
extern void matrix_chain_print(int** s, int i, int j);

MatrixChainX::MatrixChainX()
{
    m_info.id = "A-15-2";
    m_info.name = "MatrixChainX";

    m_count = 0;
    m_matrixSize = NULL;
    m_result = 0;
    m_resultMultipy = NULL;
    m_resultDevide = NULL;
}

MatrixChainX::~MatrixChainX()
{
    delete_2v_array(m_resultMultipy, m_count);
    delete_2v_array(m_resultDevide, m_count);
}

void MatrixChainX::m_BuildInput()
{
    m_count = 6;
    static int p[7] = {30, 35, 15, 5, 10, 20, 25};
    m_matrixSize = p;

    m_resultMultipy = new_2v_array(m_count);
    m_resultDevide = new_2v_array(m_count);

    printf("Input: \n");
    for (int i = 0; i < 6; i++)
        printf("  A%-7d", i+1);
    printf("\n");

    for (int i = 0; i < 6; i++)
    {
        char s[10] = {0};
        snprintf(s, 10, "%d*%d", p[i], p[i+1]);
        printf("%-10s", s);
    }
    printf("\n");
}

void MatrixChainX::m_Execute()
{
    //rod_cutting(m_price, m_size, m_resultPrice, m_resultCutting);
    m_result = matrix_chain_x(m_matrixSize, m_count, m_resultMultipy, m_resultDevide);
}

bool MatrixChainX::m_CheckOutput()
{
    printf("Result(%d): ", m_result);
    matrix_chain_print(m_resultDevide, 0, m_count-1);
    printf("\n");
    /*
    for (int i = 0; i < 6; i++)
    {
        for (int j = i; j < 6; j++)
            printf("%-8d", m_resultMultipy[i][j]);
        printf("\n");
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = i+1; j < 6; j++)
            printf("%-4d", m_resultDevide[i][j]);
        printf("\n");
    }*/
    return true;
}
