#ifndef _COUNTING_SORT_H_
#define _COUNTING_SORT_H_

#include "Algorithms.h"

class CountingSort : public Algorithms
{
public:
    CountingSort();
    virtual ~CountingSort();
protected:
    virtual void m_BuildInput();
    virtual void m_Execute();
    virtual bool m_CheckOutput();
private:
    int m_size;
    int m_max_value;
    int* m_array;
};

#endif
