// Copyright [2017] <MaoMao>

#ifndef _RADIX_SORT_H_
#define _RADIX_SORT_H_

#include "Algorithms.h"
#include <stdint.h>

class RadixSort : public Algorithms
{
 public:
    RadixSort();
    virtual ~RadixSort();
 protected:
    virtual void m_BuildInput();
    virtual void m_Execute();
    virtual bool m_CheckOutput();
 private:
    int m_size;
    int32_t* m_array;
};

#endif
