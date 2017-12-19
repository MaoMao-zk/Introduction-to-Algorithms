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
private:
    int m_size;
    int** m_matrixA;
    int** m_matrixB;
    int** m_matrixC;
};

#endif
