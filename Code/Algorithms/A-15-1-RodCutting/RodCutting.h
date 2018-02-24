// Copyright [2017] <MaoMao>

#ifndef _ROD_CUTTING_H_
#define _ROD_CUTTING_H_

#include "Algorithms.h"

class RodCutting : public Algorithms
{
 public:
     RodCutting();
    virtual ~RodCutting();
 protected:
    virtual void m_BuildInput();
    virtual void m_Execute();
    virtual bool m_CheckOutput();
 private:
    int m_size;
    int* m_price;
    int* m_resultPrice;
    int* m_resultCutting;
};

#endif
