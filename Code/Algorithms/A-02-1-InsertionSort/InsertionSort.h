#ifndef _INSERTION_SORT_H_
#define _INSERTION_SORT_H_

#include "Algorithms.h"

class InsertionSort : public Algorithms
{
public:
    InsertionSort();
    virtual ~InsertionSort();
protected:
    virtual void m_BuildInput();
    virtual void m_Execute();
    virtual void m_CheckOutput();
private:
    int m_size;
    int* m_array;
};

#endif
