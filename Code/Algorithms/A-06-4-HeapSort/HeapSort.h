#ifndef _HEAP_SORT_H_
#define _HEAP_SORT_H_

#include "Algorithms.h"

class HeapSort : public Algorithms
{
public:
    HeapSort();
    virtual ~HeapSort();
protected:
    virtual void m_BuildInput();
    virtual void m_Execute();
    virtual bool m_CheckOutput();
private:
    int m_size;
    int* m_array;
};

#endif
