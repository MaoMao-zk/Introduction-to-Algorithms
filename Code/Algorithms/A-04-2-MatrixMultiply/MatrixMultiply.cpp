// Copyright [2017] <MaoMao>

#include "MatrixMultiply.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

extern int** matrix_multiply_recursive(int** matrixA, int ** matrixB, int n);
extern int** new_2v_array(int n);
extern void delete_2v_array(int** array, int n);

MatrixMultiply::MatrixMultiply()
{
    m_info.id = "A-4-2";
    m_info.name = "MatrixMultiply";

    m_size = 0;
    m_matrixA = NULL;
    m_matrixB = NULL;
    m_matrixC = NULL;
}

MatrixMultiply::~MatrixMultiply()
{
    delete_2v_array(m_matrixA, m_size);
    delete_2v_array(m_matrixB, m_size);
    delete_2v_array(m_matrixC, m_size);
}

void MatrixMultiply::m_BuildInput()
{
    printf("Please input matrix size(n of 2^n) :\n");

    int n;
    std::cin >> n;
    assert(n >= 0);

    m_size = 1;
    for (int i = 0; i < n; i++)
        m_size *= 2;

    m_matrixA = new_2v_array(m_size);
    m_matrixB = new_2v_array(m_size);

    srand(time(NULL));
    for (int i = 0; i < m_size; i++)
    {
        for (int j = 0; j < m_size; j++)
        {
            m_matrixA[i][j] = rand()%100;
            m_matrixB[i][j] = rand()%100;
        }
    }
    matrix_print(m_matrixA, m_size);
    matrix_print(m_matrixB, m_size);
    /*
    //Example in book
    static int array[16] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    m_size = 16;
    m_array = array;
    */
}

void MatrixMultiply::matrix_print(int** matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void MatrixMultiply::m_Execute()
{
    m_matrixC = matrix_multiply_recursive(m_matrixA, m_matrixB, m_size);
}

bool MatrixMultiply::m_CheckOutput()
{
    matrix_print(m_matrixC, m_size);
    return true;
}
