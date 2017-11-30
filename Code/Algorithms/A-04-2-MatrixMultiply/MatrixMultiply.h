#ifndef _MATRIX_MULTIPLY_H_
#define _MATRIX_MULTIPLY_H_

#include "Algorithms.h"

class MatrixMultiply : public Algorithms
{
public:
    MatrixMultiply();
    virtual ~MatrixMultiply();
protected:
    virtual void m_BuildInput();
    virtual void m_Execute();
    virtual bool m_CheckOutput();
private:
    static void matrix_print(int** matrix, int n);
    //in:  matrixA matrixB
    //out: matrixC
    static void matrix_add(int** matrixA, int ** matrixB, int ** matrixC, int n);
    //n: size of matrixPartition
    static void matrix_partition(int** matrix, int **** matrixPartition, int n);
    //n: size of matrixPartition
    static void matrix_combine(int **** matrixPartition, int** matrix, int n);
    static int** matrix_multiply_recursive(int** matrixA, int ** matrixB, int n);
private:
    int m_size;
    int** m_matrixA;
    int** m_matrixB;
    int** m_matrixC;
};

#endif
