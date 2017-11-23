#include "MatrixMultiply.h"

#include <stdlib.h>
#include <time.h>
#include <iostream>


int** new_2v_array(int n)
{
    int ** array = NULL;
    array = new int*[n];
    for(int i=0;i<n;i++)
        array[i] = new int[n];

    return array;
}

void delete_2v_array(int** array, int n)
{
    if(array != NULL)
    {
        for(int i=0;i<n;i++)
            delete [] array[i];
        delete []array;
        array = NULL;
    }
}

int**** new_2v_2_2_array(int n)
{
    int **** array = NULL;
    array = new int***[2];
    for(int a=0;a<2;a++)
    {
        array[a] = new int**[2];
        for(int b=0;b<2;b++)
        {
            array[a][b] = new int*[n];
            for(int c=0;c<n;c++)
            {
                array[a][b][c] = new int[n];
            }
        }
    }

    return array;
}

void delete_2v_2_2_array(int**** array, int n)
{
    if(array != NULL)
    {
        for(int a=0;a<2;a++)
        {
            for(int b=0;b<2;b++)
            {
                for(int c=0;c<n;c++)
                {
                    delete [] array[a][b][c];
                }
                delete [] array[a][b];
            }
            delete [] array[a];
        }
        delete []array;
        array = NULL;
    }
}

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
    assert(n>=0);

    m_size = 1;
    for(int i=0;i<n;i++)
        m_size *= 2;

    m_matrixA = new_2v_array(m_size);
    m_matrixB = new_2v_array(m_size);

    srand(time(NULL));
    for(int i=0;i<m_size;i++)
    {
        for(int j=0;j<m_size;j++)
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
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void MatrixMultiply::matrix_add(int** matrixA, int ** matrixB, int ** matrixC, int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void MatrixMultiply::matrix_partition(int** matrix, int **** matrixPartition, int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            //11
            matrixPartition[0][0][i][j] = matrix[i][j];
            //12
            matrixPartition[0][1][i][j] = matrix[i][j+n];
            //21
            matrixPartition[1][0][i][j] = matrix[i+n][j];
            //22
            matrixPartition[1][1][i][j] = matrix[i+n][j+n];
        }
    }
}

void MatrixMultiply::matrix_combine(int **** matrixPartition, int** matrix, int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            //11
            matrix[i][j] = matrixPartition[0][0][i][j];
            //12
            matrix[i][j+n] = matrixPartition[0][1][i][j];
            //21
            matrix[i+n][j] = matrixPartition[1][0][i][j];
            //22
            matrix[i+n][j+n] = matrixPartition[1][1][i][j];
        }
    }
}

int** MatrixMultiply::matrix_multiply_recursive(int** matrixA, int ** matrixB, int n)
{
    int** matrixC = new_2v_array(n);
    if(n == 1)
    {
        matrixC[0][0] = matrixA[0][0] * matrixB[0][0];
    }
    else
    {
        n = n/2;
        int**** C4 = new_2v_2_2_array(n);

        //1. partition A and B
        int**** A4 = new_2v_2_2_array(n);
        matrix_partition(matrixA, A4, n);
        int**** B4 = new_2v_2_2_array(n);
        matrix_partition(matrixB, B4, n);

        //2. A4 & B4 -> C4
        int** left = NULL;
        int** right = NULL;
        //2.1 C11
        left = matrix_multiply_recursive(A4[0][0], B4[0][0], n);
        right = matrix_multiply_recursive(A4[0][1], B4[1][0], n);
        matrix_add(left, right, C4[0][0], n);
        delete_2v_array(left, n);
        delete_2v_array(right, n);
        //2.2 C12
        left = matrix_multiply_recursive(A4[0][0], B4[0][1], n);
        right = matrix_multiply_recursive(A4[0][1], B4[1][1], n);
        matrix_add(left, right, C4[0][1], n);
        delete_2v_array(left, n);
        delete_2v_array(right, n);
        //2.3 C21
        left = matrix_multiply_recursive(A4[1][0], B4[0][0], n);
        right = matrix_multiply_recursive(A4[1][1], B4[1][0], n);
        matrix_add(left, right, C4[1][0], n);
        delete_2v_array(left, n);
        delete_2v_array(right, n);
        //2.4 C22
        left = matrix_multiply_recursive(A4[1][0], B4[0][1], n);
        right = matrix_multiply_recursive(A4[1][1], B4[1][1], n);
        matrix_add(left, right, C4[01][1], n);
        delete_2v_array(left, n);
        delete_2v_array(right, n);

        //3. combine C4 to matrixC
        matrix_combine(C4, matrixC, n);

        delete_2v_2_2_array(A4, n);
        delete_2v_2_2_array(B4, n);
        delete_2v_2_2_array(C4, n);
    }
    return matrixC;
}

void MatrixMultiply::m_Execute()
{
    m_matrixC = matrix_multiply_recursive(m_matrixA, m_matrixB, m_size);
}

void MatrixMultiply::m_CheckOutput()
{
    matrix_print(m_matrixC, m_size);
}