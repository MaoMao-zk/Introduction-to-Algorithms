// Copyright [2017] <MaoMao>

#ifndef _INVERSION_H_
#define _INVERSION_H_

#include "Algorithms.h"
#include <stdint.h>

class Inversion : public Algorithms
{
 public:
    Inversion();
    virtual ~Inversion();
 protected:
    virtual void m_BuildInput();
    virtual void m_Execute();
    virtual bool m_CheckOutput();
 private:
    static int64_t merge_sort(int* array, int start, int end);
    static int64_t merge(int* array, int start, int middle, int end);
 private:
    int m_size;
    int* m_array;
    int64_t m_count;
};

#endif
