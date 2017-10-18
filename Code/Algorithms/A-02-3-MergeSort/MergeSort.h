#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_

#include "Algorithms.h"

class MergeSort : public Algorithms
{
public:
    MergeSort();
    virtual ~MergeSort();
protected:
    virtual void m_BuildInput();
    virtual void m_Execute();
    virtual void m_CheckOutput();
private:
    int m_size;
    int* m_array;
};

#endif
