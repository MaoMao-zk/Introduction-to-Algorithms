// Copyright [2017] <MaoMao>

#ifndef _MATRIX_CHAIN_X_H_
#define _MATRIX_CHAIN_X_H_

#include "Algorithms.h"

class MatrixChainX : public Algorithms
{
 public:
     MatrixChainX();
    virtual ~MatrixChainX();
 protected:
    virtual void m_BuildInput();
    virtual void m_Execute();
    virtual bool m_CheckOutput();
 private:
    int m_count;
    int* m_matrixSize;
    int m_result;
    int** m_resultMultipy;
    int** m_resultDevide;
};

#endif
