// Copyright [2017] <MaoMao>

#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_

#include "Algorithms.h"

class QuickSort : public Algorithms
{
 public:
    QuickSort();
    virtual ~QuickSort();
 protected:
    virtual void m_BuildInput();
    virtual void m_Execute();
    virtual bool m_CheckOutput();
 private:
    int m_size;
    int* m_array;
    int m_use_randomized_quick_sort;
};

#endif
