// Copyright [2017] <MaoMao>

#ifndef _LCS_H_
#define _LCS_H_

#include "Algorithms.h"

class LCS : public Algorithms
{
 public:
    LCS();
    virtual ~LCS();
 protected:
    virtual void m_BuildInput();
    virtual void m_Execute();
    virtual bool m_CheckOutput();
 private:
    char* strX;
    char* strY;
    char* strZ;  // Z is the longest common subsequence of X and Y
};

#endif
